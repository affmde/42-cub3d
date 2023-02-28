/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:57:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/28 14:57:17 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	clean_map_error(t_map *map, char *line)
{
	//ft_printf("New line error\n");
	ft_lstclear(&map->map, free);
	free(line);
	free(map);
}

static int	check_map_error(t_map *map, char *line, int *map_started)
{
	if (check_identifier(line) == 3 && *map_started)
	{
		clean_map_error(map, line);
		return (1);
	}
	return (0);
}

static t_map	*map_creator(int fd)
{
	t_map	*map;
	char	*line;
	int		map_started;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map_started = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_map_error(map, line, &map_started))
			return (NULL);
		if (check_identifier(line) == 0)
		{
			if (!map_started)
				map_started = 1;
			line = trim_line(line, "\n");
			ft_lstadd_back(&map->map, ft_lstnew(ft_strdup(line)));
		}
		free(line);
	}
	map->height = ft_lstsize(map->map);
	return (map);
}

int	parse_map(t_cub3d *cub3d, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error\n", 2);
		ft_putendl_fd("Failed to open the file", 2);
		return (1);
	}
	cub3d->map = map_creator(fd);
	if (!cub3d->map)
		return (1);
	close(fd);
	return (0);
}
