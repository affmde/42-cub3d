/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:16:33 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/17 13:16:35 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MINIMAP_SIZE 7

// void	draw_map_ray(t_cub3d *cub3d, t_ray *ray)
// {


// }

//(int)cub3d->camera->x;
//put_pixel(cub3d->img, (int)ceil(origo_x + (radius * cos(i))),
//		(int)ceil(origo_y - (radius * sin(i))), 0xFFFFFF);

void	draw_map(t_cub3d *cub3d)
{
	float	radius;
	int		x;
	int		y;

	radius = HEIGHT / 8 - 3;
	x = (int)cub3d->camera->x - (MINIMAP_SIZE / 2) + 1;
	y = (int)cub3d->camera->y - (MINIMAP_SIZE / 2);
	while (y != (int)cub3d->camera->y + (MINIMAP_SIZE / 2 + 1))
	{
		if 
	}
}

void	draw_player(t_cub3d *cub3d)
{
	int		origo_x;
	int		origo_y;
	float	radius;
	float	i;

	origo_x = WIDTH - 10 - (HEIGHT / 8 - 3);
	origo_y = HEIGHT - 10 - (HEIGHT / 8 - 3);
	radius = 1;
	while (radius != 4)
	{
		i = 0;
		while (i != 360)
		{
			put_pixel(cub3d->img, (int)ceil(origo_x + (radius * cos(i))),\
			 (int)ceil(origo_y - (radius * sin(i))), 0xFFFFFF);
			i += 1;
		}
		radius += 0.5;
	}
	draw_map(cub3d);
}

void	draw_map_frame(t_cub3d *cub3d, int radius)
{
	//0x400080
	int		origo_x;
	int		origo_y;
	float	i;

	if (radius < (HEIGHT / 8 - 5))
		return (draw_player(cub3d));
	origo_x = WIDTH - 10 - radius;
	origo_y = HEIGHT - 10 - radius;
	i = 0;
	while (i != 360)
	{
		put_pixel(cub3d->img, (int)ceil(origo_x + (radius * cos(i))), \
		(int)ceil(origo_y - (radius * sin(i))), 0xFFFFFF);
		i += .5;
	}
	draw_map_frame(cub3d, radius - 1);
}