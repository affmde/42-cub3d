/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_interact_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:58:24 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/26 16:58:27 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	check_door_char(t_cub3d *cub3d)
{
	if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'C')
		return (1);
	if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'O')
		return (1);
	if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'U')
		return (1);
	if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'D')
		return (1);
	return (0);
}

void	handle_door_open(t_cub3d *cub3d)
{
	(void)cub3d;
}