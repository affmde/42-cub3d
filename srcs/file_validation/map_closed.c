/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:58:08 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 16:53:16 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	flood_fill(t_cub3d *cub3d, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x > (int)ft_strlen(map[y])
		- 1 || y > cub3d->map->height)
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
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
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
			else if (map[i][j] == '2')
				map_check->enemies++;
			else if (map[i][j] == ' ')
				map_check->spaces++;
			else if (map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				map_check->zeros++;
			else if (map[i][j] == '@')
				map_check->hats++;
		}
	}
}

static int	check_end_space(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (++i < cub3d->map->height)
	{
		if (cub3d->map->map[i][ft_strlen(cub3d->map->map[i]) - 1] != '1')
			return (1);
	}
	return (0);
}

int	is_map_closed(t_cub3d *cub3d, t_map_check *map)
{
	int			y;
	int			x;
	t_map_check	compare;

	map->map = get_map_copy(cub3d);
	get_starting_point(map->map, &y, &x);
	map_count_elements(map->map, map);
	flood_fill(cub3d, map->map, x, y);
	map_check_init(&compare);
	map_count_elements(map->map, &compare);
	if (map->ones != compare.ones || map->spaces != compare.spaces
		|| map->hats != compare.hats
		|| compare.enemies != 0)
		return (1);
	if (check_borders(map))
		return (1);
	if (check_end_space(cub3d))
		return (1);
	clean_char_arr(map->map);
	if (map_outside_chars(cub3d, map))
		return (1);
	return (0);
}
