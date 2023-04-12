/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/12 13:18:34 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_cub3d *cub3d, t_ray *ray)
{
	float	ray_cos;
	float	ray_sin;

	float x = cub3d->camera->x / scale;
	float y = cub3d->camera->y / scale;
	ray_cos = cosf(degrees_to_radians(ray->angle)) / 100;
	ray_sin = sinf(degrees_to_radians(ray->angle)) / 100;
	while (1)
	{
		x += ray_cos;
		y += ray_sin;
		if (cub3d->map->map[(int)floor(y)][(int)floor(x)] == '1')
			break ;
	}
	float distance = sqrt(pow(cub3d->camera->x / scale - x, 2) + pow(cub3d->camera->y / scale - y, 2));
	ray->distance = distance * scale;
}


void	draw_ray(t_cub3d *cub3d, t_img *img, t_ray *ray)
{
	float	distance;

	ray->start.x = cub3d->camera->x;
	ray->start.y = cub3d->camera->y;
	ray->start.color = 0xFFFF00;
	distance = ray->distance;
	ray->end.x = ray->start.x + distance * cos(degrees_to_radians(ray->angle));
	ray->end.y = ray->start.y + distance * sin(degrees_to_radians(ray->angle));
	ray->end.color = 0xFFFF00;
	bresenham_algo(ray->start, ray->end, img);
}

void	draw_wall(t_cub3d *cub3d, int color, t_pos *start, t_pos *end)
{
	start->color = color;
	end->color = color;
	bresenham_algo(*start, *end, cub3d->img);
}

void	draw_col(t_cub3d *cub3d, t_ray *ray)
{
	float	wallHeight;
	float	distance;
	t_pos	start;
	t_pos	end;

	distance = ray->distance * cos(degrees_to_radians(ray->angle - cub3d->camera->player_angle));
	wallHeight = cub3d->camera->half_height / distance * scale;
	start.x = ray->index;
	start.y = cub3d->camera->half_height - wallHeight;
	end.x = ray->index;
	end.y = cub3d->camera->half_height + wallHeight;
	draw_wall(cub3d, 0xffffff, &start, &end);
	start.x = ray->index;
	start.y = 0;
	end.x = ray->index;
	end.y = cub3d->camera->half_height - wallHeight;
	draw_wall(cub3d, 0x0000FF, &start, &end);
	start.x = ray->index;
	start.y = cub3d->camera->half_height + wallHeight;
	end.x = ray->index;
	end.y = HEIGHT;
	draw_wall(cub3d, 0x00FF00, &start, &end);
}
