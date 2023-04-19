/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 08:51:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/18 17:43:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_init(t_cub3d *cub3d)
{
	cub3d->img.img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	if (!cub3d->img.img_ptr)
		error_msg_exit("Failed to create image");
	cub3d->img.data = (int *)mlx_get_data_addr(cub3d->img.img_ptr,
			&cub3d->img.bpp, &cub3d->img.size_l, &cub3d->img.endian);
	if (!cub3d->img.data)
		error_msg_exit("Failed to get image data");
}
