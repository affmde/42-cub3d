/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 16:42:52 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_steps(t_cub3d *cub3d, int x)
{
	if (cub3d->ray.dir_x[x] < 0)
	{
		cub3d->ray.step_x = -1;
		cub3d->ray.side_dist_x = (cub3d->camera.x - cub3d->ray.map_x)
			* cub3d->ray.delta_dist_x;
	}
	else
	{
		cub3d->ray.step_x = 1;
		cub3d->ray.side_dist_x = (cub3d->ray.map_x + 1.0 - cub3d->camera.x)
			* cub3d->ray.delta_dist_x;
	}
	if (cub3d->ray.dir_y[x] < 0)
	{
		cub3d->ray.step_y = -1;
		cub3d->ray.side_dist_y = (cub3d->camera.y - cub3d->ray.map_y)
			* cub3d->ray.delta_dist_y;
	}
	else
	{
		cub3d->ray.step_y = 1;
		cub3d->ray.side_dist_y = (cub3d->ray.map_y + 1.0 - cub3d->camera.y)
			* cub3d->ray.delta_dist_y;
	}
}

static void	dda_algo(t_cub3d *cub3d, int x, int shoot)
{
	while (cub3d->ray.hit == 0)
	{
		if (cub3d->ray.side_dist_x < cub3d->ray.side_dist_y)
		{
			cub3d->ray.side_dist_x += cub3d->ray.delta_dist_x;
			cub3d->ray.map_x += cub3d->ray.step_x;
			if (cub3d->ray.dir_x[x] > 0)
				cub3d->ray.direction = EAST;
			else
				cub3d->ray.direction = WEST;
		}
		else
		{
			cub3d->ray.side_dist_y += cub3d->ray.delta_dist_y;
			cub3d->ray.map_y += cub3d->ray.step_y;
			if (cub3d->ray.dir_y[x] > 0)
				cub3d->ray.direction = SOUTH;
			else
				cub3d->ray.direction = NORTH;
		}
		(void)shoot;
		if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == '1')
			cub3d->ray.hit = 1;
	}
}

static void	calculate_distance(t_cub3d *cub3d, int x)
{
	if (cub3d->ray.direction == EAST || cub3d->ray.direction == WEST)
		cub3d->ray.perp_wall_dist = (cub3d->ray.map_x - cub3d->camera.x
				+ (1 - cub3d->ray.step_x) / 2) / cub3d->ray.dir_x[x];
	else
		cub3d->ray.perp_wall_dist = (cub3d->ray.map_y - cub3d->camera.y
				+ (1 - cub3d->ray.step_y) / 2) / cub3d->ray.dir_y[x];
	cub3d->z_buffer[x] = cub3d->ray.perp_wall_dist;
	cub3d->ray.line_height = (int)(HEIGHT / cub3d->ray.perp_wall_dist);
	cub3d->ray.r_start = cub3d->camera.half_height
		- cub3d->ray.line_height / 2;
	if (cub3d->ray.r_start < 0)
		cub3d->ray.r_start = 0;
	cub3d->ray.r_end = cub3d->camera.half_height
		+ cub3d->ray.line_height / 2;
	if (cub3d->ray.r_end >= HEIGHT)
		cub3d->ray.r_end = HEIGHT - 1;
}

void	raycasting(t_cub3d *cub3d, int x, int shoot)
{
	cub3d->camera.cam_x = 2 * x / (double)WIDTH - 1;
	cub3d->ray.dir_x[x] = cub3d->camera.dir_x + cub3d->camera.plane_x
		* cub3d->camera.cam_x;
	cub3d->ray.dir_y[x] = cub3d->camera.dir_y + cub3d->camera.plane_y
		* cub3d->camera.cam_x;
	cub3d->ray.map_x = (int)cub3d->camera.x;
	cub3d->ray.map_y = (int)cub3d->camera.y;
	cub3d->ray.delta_dist_x = fabs(1 / cub3d->ray.dir_x[x]);
	cub3d->ray.delta_dist_y = fabs(1 / cub3d->ray.dir_y[x]);
	cub3d->ray.hit = 0;
	get_steps(cub3d, x);
	dda_algo(cub3d, x, shoot);
	if (shoot)
		return ;
	calculate_distance(cub3d, x);
	render(cub3d);
}

void	raycast_environemt(t_cub3d *cub3d)
{
	cub3d->ray.index = 0;
	while (cub3d->ray.index < WIDTH)
	{
		raycasting(cub3d, cub3d->ray.index, 0);
		cub3d->ray.index++;
	}
	draw_map_tiles(cub3d);
	mlx_put_image_to_window(cub3d->ptr, cub3d->win, cub3d->img.img_ptr, 0, 0);
}
