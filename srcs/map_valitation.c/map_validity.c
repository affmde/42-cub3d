/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:17:36 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/26 20:23:42 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_check_iniit(t_map_check *map_check)
{
	map_check->zeros = 0;
	map_check->ones = 0;
	map_check->ones = 0;
}

int	valid_map(t_cub3d *cub3d)
{
	t_map_check map_check;

	map_check_iniit(&map_check);
	return (0);
}