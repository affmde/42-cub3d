/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:08:30 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/26 13:34:15 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_start_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	add_values_to_compare(t_map_check *a, t_map_check *b)
{
	a->ones = b->ones;
	a->spaces = b->spaces;
	a->zeros = b->zeros;
	a->hats = b->hats;
}

int	door_validity(char **map)
{
	(void)map;
	return (0);
}
