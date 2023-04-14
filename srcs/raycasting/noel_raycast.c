/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noel_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:38:41 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/12 16:38:43 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_wall(float x, float y, t_cub3d *cub3d, t_ray *ray)
{
	float	inc_x;
	float	inc_y;

	inc_x = cosf(degrees_to_radians(ray->angle)) / 1000;
	inc_y = sinf(degrees_to_radians(ray->angle)) / 1000;
	while (1)
	{
		if (cub3d->map->map[(int)y][(int)x] == '1')
			break ;
		x += inc_x;
		y += inc_y;
	}
	ray->distance = (sqrt(pow(cub3d->camera->x / scale - x, 2) \
	+ pow(cub3d->camera->y / scale - y, 2))) * scale;
}

void	draw_column(t_cub3d *cub3d, t_ray *ray)
{
	float	wall_height;
	float	distance;
	t_pos	start;
	t_pos	end;

	find_wall(cub3d->camera->x / scale, cub3d->camera->y / scale, cub3d, ray);
	distance = ray->distance * cos(degrees_to_radians \
	(ray->angle - cub3d->camera->player_angle));
	wall_height = cub3d->camera->half_height / distance * scale;
	start.x = ray->index;
	end.x = ray->index;
	start.y = cub3d->camera->half_height - wall_height;
	end.y = cub3d->camera->half_height + wall_height;
	draw_wall(cub3d, 0xFFFFFFF, &start, &end);
	start.y = 0;
	end.y = cub3d->camera->half_height - wall_height;
	draw_wall(cub3d, 0x0000FF, &start, &end);
	start.y = cub3d->camera->half_height + wall_height;
	end.y = HEIGHT;
	draw_wall(cub3d, 0x00FF00, &start, &end);
}
