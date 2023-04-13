/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/13 22:11:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	raycasting(t_cub3d *cub3d, t_ray *ray)
{
	float	ray_cos;
	float	ray_sin;
	float	distance;
	float	x;
	float	y;

	x = cub3d->camera->x / scale;
	y = cub3d->camera->y / scale;
	ray_cos = cos(degrees_to_radians(ray->angle)) / 100;
	ray_sin = sin(degrees_to_radians(ray->angle)) / 100;
	while (1)
	{
		x += ray_cos;
		y += ray_sin;
		if (cub3d->map->map[(int)floor(y)][(int)floor(x)] == '1')
			break ;
	}
	distance = sqrt(pow(cub3d->camera->x / scale - x, 2) \
		+ pow(cub3d->camera->y / scale - y, 2));
	ray->distance = distance * scale;
	ray->wall_hit_x = x;
	ray->wall_hit_y = y;
}*/

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
		ray->side_dist_x = (ray->map_x + 1.0 - cub3d->camera->x) * ray->delta_dist_x;
	}
	if (ray->dir_y)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub3d->camera->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub3d->camera->y) * ray->delta_dist_y;
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
	printf("wall detected at y: %d x: %d\n", ray->map_x, ray->map_y);
}

void	raycasting(t_cub3d *cub3d, t_ray *ray)
{
	ray->index = 0;
	while (ray->index < WIDTH)
	{
		cub3d->camera->x = 2 * ray->index / (double)WIDTH - 1;
		ray->dir_x = cub3d->camera->x + cub3d->camera->plane_x * cub3d->camera->x;
		ray->dir_y = cub3d->camera->y + cub3d->camera->plane_y * cub3d->camera->x;
		ray->map_x = (int)cub3d->camera->x;
		ray->map_y = (int)cub3d->camera->y;
		ray->delta_dist_x = fabs(1 / ray->dir_x);
		ray->delta_dist_y = fabs(1 / ray->dir_y);
		ray->hit = 0;
		get_steps(cub3d, ray);
		dda_algo(cub3d, ray);
		ray->index++;
	}
}