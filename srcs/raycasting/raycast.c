/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/06 22:38:51 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	raycasting(t_cub3d *cub3d, float angle)
{
	float	ray_angle;
	float	ray_cos;
	float	ray_sin;
	char	c;
	
	ray_angle = angle;
	float x = cub3d->camera->x / scale;
	float y = cub3d->camera->y / scale;
	ray_cos = cosf(degrees_to_radians(ray_angle)) / scale;
	ray_sin = sinf(degrees_to_radians(ray_angle)) / scale;
	c = '0';
	while (c != '1')
	{
		x += ray_cos;
		y += ray_sin;
		c = cub3d->map->map[(int)floor(y)][(int)floor(x)];
	}
	float distance = sqrt(pow(cub3d->camera->x / scale - x, 2) + pow(cub3d->camera->y / scale - y, 2));
	return (distance);
}

void	draw_ray(t_cub3d *cub3d, t_img *img, float angle, int i)
{
	float	distance;
	//t_pos	a;
	//t_pos	b;
	float wallHeight;
	
	//a.x = cub3d->camera->x;
	//a.y = cub3d->camera->y;
	//a.color = 0xFFFF00;
	distance = raycasting(cub3d, angle) * scale;
	distance = distance * cos(degrees_to_radians(angle - cub3d->camera->player_angle));
	//b.x = a.x + distance * cos(degrees_to_radians(angle));
	//b.y = a.y + distance * sin(degrees_to_radians(angle)); 
	//b.color = 0xFFFF00;
	//bresenham_algo(a, b, img);
	wallHeight = cub3d->camera->half_height / distance * scale;
	printf("wallHeight: %f, half_H: %f\n", wallHeight, cub3d->camera->half_height);
	t_pos	c;
	t_pos	d;
	c.x = i;
	c.y = cub3d->camera->half_height - wallHeight;
	c.color = 0xffffff;
	d.x = i;
	d.y = cub3d->camera->half_height + wallHeight;
	bresenham_algo(c, d, img);
	c.x = i;
	c.y = 0;
	c.color = 0x0000FF;
	d.x = i;
	d.y = cub3d->camera->half_height - wallHeight;
	bresenham_algo(c, d, img);
	c.x = i;
	c.y = cub3d->camera->half_height + wallHeight;
	c.color = 0x00FF00;
	d.x = i;
	d.y = HEIGHT;
	bresenham_algo(c, d, img);
}