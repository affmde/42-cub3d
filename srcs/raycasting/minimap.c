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

#define MINIMAP_SIZE 7               //mv this
#define MINI_RAY_ACCURACY 5
#define MINI_RAY_DIST 25
#define MINI_RAY_MAX_DIST 60

//(int)cub3d->camera.x;
//square size = (HEIGHT / 8 - 5) * 2

int	detect_color(t_cub3d *cub3d, int x, int y)
{
	int	y2;
	int	x2;
	
	y = (HEIGHT - y - 10) / ((HEIGHT / 8 - 5) * 2 / MINIMAP_SIZE);
	x = (WIDTH - x - 10) / ((HEIGHT / 8 - 5) * 2 / MINIMAP_SIZE);
	x2 = x + (int)cub3d->camera.x - (MINIMAP_SIZE / 2);
	y2 = y + (int)cub3d->camera.y - (MINIMAP_SIZE / 2);
	if (y2 < 0 || y2 >= cub3d->map->height)
		return (0x000000);
	if (x2 < 0 || (size_t)x2 >= ft_strlen(cub3d->map->map[y2]))
		return (0x000000);
	if (cub3d->map->map[y2][x2] == ' ')
		return (0x000000);
	if (cub3d->map->map[y2][x2] == '1')
		return (0x006600);
	if (cub3d->map->map[y2][x2] == '2')
		return (0x800040);
	return (0x66FF66);
}

void	draw_player(t_cub3d *cub3d)
{
	float	origo_x;
	float	origo_y;
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
			put_pixel(&cub3d->img, (int)ceil(origo_x + (radius * cos(i))),\
			 (int)ceil(origo_y - (radius * sin(i))), 0xE60000);
			i += 1;
		}
		radius += 0.5;
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
		dist_x = (cub3d->ray.dir_x[cub3d->ray.index] * MINI_RAY_DIST * -1 * cub3d->z_buffer[cub3d->ray.index]);
		dist_y = (cub3d->ray.dir_y[cub3d->ray.index] * MINI_RAY_DIST * -1 * cub3d->z_buffer[cub3d->ray.index]);
		start = populate_position(origo_x, origo_y, 0, 0xFFFFFF);
		end = populate_position((int)(origo_x + dist_x), (int)(origo_y + dist_y), 0, 0xFFFFFF);
		bresenham_algo(start, end, &cub3d->img);
		cub3d->ray.index += MINI_RAY_ACCURACY;
	}
	draw_player(cub3d);
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
			(int)ceil(origo_y - (radius * sin(i))), detect_color(cub3d, (int)ceil(origo_x \
			+ (radius * cos(i))), (int)ceil(origo_y - (radius * sin(i)))));
			i += .7;
			// if one wants a completely full circle one can replace the above index increase with this vv
			//i += .1
			// if (radius < 70)
			// 	i += .2;
			// if (radius < 40)
			// 	i += .3;
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
		return (draw_map_rays(cub3d, WIDTH - 10 - (HEIGHT / 8 - 3), \
		HEIGHT - 10 - (HEIGHT / 8 - 3)));
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