/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_validation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:06:36 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/26 13:44:16 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	invalid_empty_char(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' ||
	c == 'S' || c == '2' || c == '0')
		return (0);
	return (1);
}

int	check_corners(char **map, int x, int y)
{
	if (map[y - 1][x - 1] != '1')
		return (1);
	if (map[y - 1][x + 1] != '1')
		return (1);
	if (map[y + 1][x - 1] != '1')
		return (1);
	if (map[y + 1][x + 1] != '1')
		return (1);
	return (0);
}

int	door_sideways(char **map, int x, int y)
{
	if (x < 1 || y < 1 || !map[y][x + 1] || !map[y + 1])
		return (1);
	if (check_corners(map, x, y))
		return (1);
	if (invalid_empty_char(map[y][x - 1]) ||
	invalid_empty_char(map[y][x + 1]))
		return (1);
	if (map[y - 1][x] != '1' || map[y + 1][x] != '1')
		return (1);
	return (0);
}

int	door_vertical(char **map, int x, int y)
{
	if (x < 1 || y < 1 || !map[y][x + 1] || !map[y + 1])
		return (1);
	if (check_corners(map, x, y))
		return (1);
	if (map[y][x - 1] != '1' || map[y][x + 1] != '1')
		return (1);
	if (invalid_empty_char(map[y - 1][x]) ||
	invalid_empty_char(map[y + 1][x]))
		return (1);
	return (0);
}

int	door_validity(char **map)
{
	int	y;
	int	x;
	int	check;

	y = 0;
	check = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'C' || map[y][x] == 'O'))
				check = door_sideways(map, x, y);
			if (check)
				check = door_vertical(map, x, y);
			if (check)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
