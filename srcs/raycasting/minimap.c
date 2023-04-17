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

#define HALF_MAP 

// void	draw_map_ray(t_cub3d *cub3d, t_ray *ray)
// {


// }

void	draw_rows(t_cub3d *cub3d, int h)
{
	t_pos	start;
	t_pos	end;
	int		i;

	i = 0;
	while (i != 12)
	{
		start = populate_position(WIDTH - 256, HEIGHT - h - i, 0, 0x04D0099);
		end = populate_position(WIDTH - 32, HEIGHT - h - i, 0, 0x04D0099);
		bresenham_algo(start, end, cub3d->img);
		i++;
	}
}

void	draw_cols(t_cub3d *cub3d, int w)
{
	t_pos	start;
	t_pos	end;
	int		i;

	i = 0;
	while (i != 12)
	{
		start = populate_position(WIDTH - w - i, HEIGHT - 267, 0, 0x04D0099);
		end = populate_position(WIDTH - w - i, HEIGHT - 31, 0, 0x04D0099);
		bresenham_algo(start, end, cub3d->img);
		i++;
	}
}

void	draw_player(t_cub3d *cub3d)
{
	t_pos	start;
	t_pos	end;
	int		i;
	int		w;
	int		h;

	i = 0;
	w = 143;
	h = 143;
	while (i != 10)
	{
		start = populate_position(WIDTH - w - i, HEIGHT - h, 0, 0x04D0099);
		end = populate_position(WIDTH - w - i, HEIGHT - h - 10, 0, 0x04D0099);
		bresenham_algo(start, end, cub3d->img);
		i++;
	}
}

void	draw_map_frame(t_cub3d *cub3d)
{
	draw_rows(cub3d, 256);
	draw_rows(cub3d, 32);
	draw_cols(cub3d, 256);
	draw_cols(cub3d, 32);
	draw_player(cub3d);
}