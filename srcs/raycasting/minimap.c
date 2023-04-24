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

int	detect_color(t_cub3d *cub3d, float x, float y)
{
	float	y2;
	float	x2;

	y = (HEIGHT - y - 23.5) / ((HEIGHT / 8 - 5) * 2 / MINIMAP_SIZE);
	x = (WIDTH - x - 23.5) / ((HEIGHT / 8 - 5) * 2 / MINIMAP_SIZE);
	x2 = x + cub3d->camera.x - (MINIMAP_SIZE / 2);
	y2 = y + cub3d->camera.y - (MINIMAP_SIZE / 2);
	if (y2 < 0 || y2 >= cub3d->map->height)
		return (0x000000);
	if (x2 < 0 || (size_t)x2 >= ft_strlen(cub3d->map->map[(int)y2]))
		return (0x000000);
	if (cub3d->map->map[(int)y2][(int)x2] == ' ')
		return (0x000000);
	if (cub3d->map->map[(int)y2][(int)x2] == '1')
		return (0x006600);
	return (0x66FF66);
}

void	draw_player(t_cub3d *cub3d)
{
	float	origo_x;
	float	origo_y;
	float	radius;
	float	i;

	origo_x = WIDTH - 10 - (HEIGHT / 8 - 5);
	origo_y = HEIGHT - 10 - (HEIGHT / 8 - 5);
	radius = 1;
	while (radius != 4)
	{
		i = 0;
		while (i != 360)
		{
			put_pixel(&cub3d->img, (int)ceil(origo_x + (radius * cos(i))), \
			(int)ceil(origo_y - (radius * sin(i))), 0xE60000);
			i += 1;
		}
		radius += 0.5;
	}
}

void	draw_map_tiles(t_cub3d *cub3d)
{
	float	radius;
	int		origo_x;
	int		origo_y;
	float	i;

	radius = HEIGHT / 8 - 5;
	origo_x = WIDTH - 10 - radius;
	origo_y = HEIGHT - 10 - radius;
	while (radius > 0)
	{
		i = 0;
		while (i < 360)
		{
			put_pixel(&cub3d->img, (int)ceil(origo_x + (radius * cos(i))), \
			(int)ceil(origo_y - (radius * sin(i))), \
			detect_color(cub3d, (int)ceil(origo_x \
			+ (radius * cos(i))), (int)ceil(origo_y - (radius * sin(i)))));
			i += .7;
		}
		radius -= .5;
	}
	draw_map_frame(cub3d, HEIGHT / 8);
}

void	draw_map_frame(t_cub3d *cub3d, int radius)
{
	int		origo_x;
	int		origo_y;
	float	i;

	if (radius < (HEIGHT / 8 - 5))
		return (draw_map_rays(cub3d, WIDTH - 10 - (HEIGHT / 8 - 5), \
		HEIGHT - 10 - (HEIGHT / 8 - 5)));
	origo_x = WIDTH - 10 - radius;
	origo_y = HEIGHT - 10 - radius;
	i = 0;
	while (i != 360)
	{
		put_pixel(&cub3d->img, (int)ceil(origo_x + (radius * cos(i))), \
		(int)ceil(origo_y - (radius * sin(i))), 0x004D00);
		i += .5;
	}
	draw_map_frame(cub3d, radius - 1);
}
