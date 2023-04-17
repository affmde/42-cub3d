/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 08:51:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/15 09:02:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_init(t_cub3d *cub3d)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		error_msg_exit("Failed to create image");
	img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	if (!img->img_ptr)
		error_msg_exit("Failed to create image");
	img->data = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_l, &img->endian);
	if (!img->data)
		error_msg_exit("Failed to get image data");
	cub3d->img = img;
}
