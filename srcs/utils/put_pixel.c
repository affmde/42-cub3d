/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:37:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 14:38:00 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_img *image, int x, int y, int color)
{
	int		offset;

	offset = y * (image->size_l / 4) + x;
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		image->data[offset] = color;
}