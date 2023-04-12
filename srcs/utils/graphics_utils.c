/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:05 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/12 15:06:19 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh_window(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->ptr, cub3d->win);
	mlx_destroy_image(cub3d->ptr, cub3d->img->img_ptr);
	free(cub3d->img);
	draw(cub3d);
}

void	put_pixel(t_img *image, int x, int y, int color)
{
	int		offset;

	if (color == (int)0xFF000000)
	return ;

	offset = y * (image->size_l / 4) + x;
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		image->data[offset] = color;
}
