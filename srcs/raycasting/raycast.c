/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/15 10:19:51 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_steps(t_cub3d *cub3d, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub3d->camera->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub3d->camera->x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub3d->camera->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub3d->camera->y)
			* ray->delta_dist_y;
	}
}

static void	dda_algo(t_cub3d *cub3d, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->dir_x > 0)
				ray->direction = EAST;
			else
				ray->direction = WEST;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->dir_y > 0)
				ray->direction = SOUTH;
			else
				ray->direction = NORTH;
		}
		if (cub3d->map->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	calculate_distance(t_cub3d *cub3d, t_ray *ray)
{
	if (ray->direction == EAST || ray->direction == WEST)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->r_start = cub3d->camera->half_height - ray->line_height / 2;
	ray->r_end = cub3d->camera->half_height + ray->line_height / 2;
	if (ray->direction == EAST || ray->direction == WEST)
		ray->wall_hit_x = cub3d->camera->y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_hit_x = cub3d->camera->x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_hit_x = floor(ray->wall_hit_x);
}

void	raycasting(t_cub3d *cub3d, t_ray *ray)
{
	ray_reset_values(cub3d, ray);
	while (ray->index < WIDTH)
	{
		cub3d->camera->cam_x = 2 * ray->index / (double)WIDTH - 1;
		ray->dir_x = cub3d->camera->dir_x + cub3d->camera->plane_x
			* cub3d->camera->cam_x;
		ray->dir_y = cub3d->camera->dir_y + cub3d->camera->plane_y
			* cub3d->camera->cam_x;
		ray->map_x = (int)cub3d->camera->x;
		ray->map_y = (int)cub3d->camera->y;
		ray->delta_dist_x = fabs(1 / ray->dir_x);
		ray->delta_dist_y = fabs(1 / ray->dir_y);
		ray->hit = 0;
		get_steps(cub3d, ray);
		dda_algo(cub3d, ray);
		calculate_distance(cub3d, ray);
		render(cub3d, ray);
		ray->index++;
	}
	mlx_put_image_to_window(cub3d->ptr, cub3d->win, cub3d->img->img_ptr, 0, 0);
}
