/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:17:36 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/01 14:07:04 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_characters(char **map, t_map_check *map_check)
{
	int		i;
	int		j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				map_check->other_chars++;
			if (is_start_pos(map[i][j]))
				map_check->start_position++;
			j++;
		}
		if (!ft_strncmp(map[i], "\n", ft_strlen(map[i])))
			map_check->empty_lines++;
		i++;
	}
}

int	valid_map(t_cub3d *cub3d)
{
	t_map_check map_check;

	map_check.start_position = 0;
	map_check.other_chars = 0;
	map_check.empty_lines = 0;
	check_characters(cub3d->map->map, &map_check);
	if (map_check.other_chars)
		return (1);
	if (map_check.start_position != 1)
		return (1);
	if (map_check.empty_lines)
		return (1);
	return (0);
}
