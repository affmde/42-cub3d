/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:20:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/03 13:21:45 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_borders(t_map_check *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '#' || map->map[i][j] == '0')
			{
				if (map->map[i - 1][j] == '@' || map->map[i + 1][j] == '@'
				|| map->map[i][j - 1] == '@' || map->map[i][j + 1] == '@')
					return (1);
			}
			if (map->map[i][j] == '0')
			{
				if (map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' '
				|| map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' ')
					return (1);
			}
		}
	}
	return (0);
}
