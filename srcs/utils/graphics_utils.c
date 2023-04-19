/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:05 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/19 09:25:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *image, int x, int y, int color)
{
	int		offset;

	if (color == (int)0xFF000000)
		return ;
	offset = y * (image->size_l >> 2) + x;
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		image->data[offset] = color;
}
