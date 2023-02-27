/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:57:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 09:57:19 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static t_map	*map_creator(int fd)
{
	t_map	*map;
	char	*line;
	
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (check_identifier(line) == 0)
			ft_lstadd_back(&map->map, ft_lstnew(ft_strdup(line)));
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
		ft_putendl_fd("Failed to open the file", 2);
		return (1);
	}
	cub3d->map = map_creator(fd);
	if (!cub3d->map)
		return (1);
	close(fd);
	return (0);
}