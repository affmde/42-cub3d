/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:58:08 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/02 16:12:34 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*line_add_border(char *line, t_cub3d *cub3d)
{
	char	*str;
	int		i;
	int		total_chars;

	total_chars = cub3d->map->max_length + 3;
	str = ft_calloc(total_chars, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	str[i++] = '@';
	ft_memcpy(&str[i], line, ft_strlen(line));
	i += ft_strlen(line);
	while (i < total_chars - 1)
		str[i++] = '@';
	str[i] = '\0';
	return (str);
}

static char **get_map_copy(t_cub3d *cub3d)
{
	char	**arr;
	int		i;
	
	arr = ft_calloc(cub3d->map->height + 3, sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = ft_calloc(cub3d->map->max_length + 3, sizeof(char));
	if (!arr[0])
		return (NULL);
	ft_memset(arr[0], '@', cub3d->map->max_length + 2);
	arr[0][cub3d->map->max_length + 2] = '\0';
	i = 0;
	while (i < cub3d->map->height)
	{
		arr[i + 1] = line_add_border(cub3d->map->map[i], cub3d);
		if (!arr[i + 1])
			return (NULL);
		i++;
	}
	arr[i + 1] = ft_calloc(cub3d->map->max_length + 3, sizeof(char));
	if (!arr[0])
		return (NULL);
	ft_memset(arr[i + 1], '@', cub3d->map->max_length + 2);
	arr[i + 1][cub3d->map->max_length + 2] = '\0';
	i++;
	arr[i + 1] = NULL;
	return (arr);
}

static void flood_fill(t_cub3d *cub3d, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x > (int)ft_strlen(map[y]) - 1 || y > cub3d->map->height)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == '#')
		return ;
	map[y][x] = '#';
	flood_fill(cub3d, map, x + 1, y);
	flood_fill(cub3d, map, x - 1, y);
	flood_fill(cub3d, map, x, y + 1);
	flood_fill(cub3d, map, x, y - 1);
}

static void	get_starting_point(char **map, int *y, int *x)
{
	int	i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	map_count_elements(char **map, t_map_check *map_check)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				map_check->ones++;
			else if (map[i][j] == ' ')
				map_check->spaces++;
			else if(map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				map_check->zeros++;
			else if (map[i][j] == '@')
				map_check->hats++;
		}
	}
}

int	is_map_closed(t_cub3d *cub3d, t_map_check *map)
{
	int	y;
	int	x;
	t_map_check compare;
	
	map->map = get_map_copy(cub3d);
	get_starting_point(map->map, &y, &x);
	map_count_elements(map->map, map);
	flood_fill(cub3d, map->map, x, y);
	map_check_init(&compare);
	map_count_elements(map->map, &compare);
	if (map->ones != compare.ones || map->spaces != compare.spaces || compare.zeros != 0 || map->hats != compare.hats)
		return (1);
	return (0);
}