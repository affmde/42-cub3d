/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:50:46 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/24 15:50:47 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cut_down_ray(t_cub3d *cub3d, float *dist_x, float *dist_y)
{
	float	dif;

	dif = RAY_LEN_ACCURACY;
	while (hypot(*dist_x, *dist_y) > MINI_RAY_MAX_DIST)
	{
		*dist_x = (cub3d->ray.dir_x[cub3d->ray.index] * \
		(MINI_RAY_DIST - dif) * -1 * cub3d->z_buffer[cub3d->ray.index]);
		*dist_y = (cub3d->ray.dir_y[cub3d->ray.index] * \
		(MINI_RAY_DIST - dif) * -1 * cub3d->z_buffer[cub3d->ray.index]);
		dif += RAY_LEN_ACCURACY;
	}
}

void	draw_map_rays(t_cub3d *cub3d, float origo_x, float origo_y)
{
	t_pos	start;
	t_pos	end;
	float	dist_x;
	float	dist_y;

	cub3d->ray.index = 0;
	while (cub3d->ray.index < WIDTH)
	{
		dist_x = (cub3d->ray.dir_x[cub3d->ray.index] * \
		MINI_RAY_DIST * -1 * cub3d->z_buffer[cub3d->ray.index]);
		dist_y = (cub3d->ray.dir_y[cub3d->ray.index] * \
		MINI_RAY_DIST * -1 * cub3d->z_buffer[cub3d->ray.index]);
		cut_down_ray(cub3d, &dist_x, &dist_y);
		start = populate_position(origo_x, origo_y, 0, 0xFFFF00);
		end = populate_position((int)(origo_x + dist_x), \
		(int)(origo_y + dist_y), 0, 0xFFFF00);
		bresenham_algo(start, end, &cub3d->img);
		cub3d->ray.index += MINI_RAY_ACCURACY;
	}
	draw_player(cub3d);
}
