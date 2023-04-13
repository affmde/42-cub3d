/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/13 12:31:00 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_cub3d *cub3d, t_ray *ray)
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

static void	define_wall_texture(t_pos *start, t_pos *end,
	t_cub3d *cub3d, t_ray *ray)
{
	start->x = ray->index;
	start->y = cub3d->camera->half_height - ray->wall_height;
	start->color = 0xffffff;
	end->x = ray->index;
	end->y = cub3d->camera->half_height + ray->wall_height;
	if (ray->index < 50)
		printf("inde: %d startX: %d, startY: %d, endX: %d endY: %d\n",ray->index, start->x, start->y, end->x, end->y);
}

static void	draw_layer(t_cub3d *cub3d, int wall_height, char *type, t_ray *ray)
{
	t_pos	start;
	t_pos	end;

	if (!ft_strncmp(type, "ceiling", ft_strlen(type)))
	{
		start.x = ray->index;
		start.y = 0;
		start.color = create_rgb(get_wall_color("C", cub3d));
		end.x = ray->index;
		end.y = cub3d->camera->half_height - wall_height;
	}
	else if (!ft_strncmp(type, "floor", ft_strlen(type)))
	{
		start.x = ray->index;
		start.y = cub3d->camera->half_height + wall_height;
		start.color = create_rgb(get_wall_color("F", cub3d));
		end.x = ray->index;
		end.y = HEIGHT;
	}
	else
		define_wall_texture(&start, &end, cub3d, ray);
	bresenham_algo(start, end, cub3d->img);
}

void	draw_col(t_cub3d *cub3d, t_ray *ray)
{
	float	distance;

	distance = ray->distance * cos(degrees_to_radians(ray->angle \
		- cub3d->camera->player_angle));
	ray->wall_height = cub3d->camera->half_height / distance * scale;
	if (ray->index < 50)
		printf("inde: %d wall height: %d ray distance: %f\n",ray->index, ray->wall_height, ray->distance);
	draw_layer(cub3d, ray->wall_height, "ceiling", ray);
	draw_layer(cub3d, ray->wall_height, "floor", ray);
	draw_layer(cub3d, ray->wall_height, "wall", ray);
}
