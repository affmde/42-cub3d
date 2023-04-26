/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blood_splatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:53:27 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/26 09:42:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	blood_splatter_texture(t_cub3d *cub3d)
{
	cub3d->blood.blood_texture.img = ft_calloc(1, sizeof(t_img));
	if (!cub3d->blood.blood_texture.img)
		error_msg_exit("couldn't load blood splatter texture");
	cub3d->blood.blood_texture.img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr, "./textures/blood_splatter.xpm",
		&cub3d->blood.blood_texture.width, &cub3d->blood.blood_texture.height);
	if (!cub3d->blood.blood_texture.img->img_ptr)
		error_msg_exit("couldn't load blood splatter texture");
	cub3d->blood.blood_texture.img->data = (int *)mlx_get_data_addr(cub3d->blood.blood_texture.img->img_ptr,
		&cub3d->blood.blood_texture.img->bpp, &cub3d->blood.blood_texture.img->size_l,
		&cub3d->blood.blood_texture.img->endian);
	if (!cub3d->blood.blood_texture.img->data)
		error_msg_exit("couldn't load blood splatter texture");
	cub3d->blood.is_rendering = 0;
	cub3d->blood.time = 0;
	printf("h: %d w: %d\n", cub3d->blood.blood_texture.height, cub3d->blood.blood_texture.width);
}

void	blood_splatter_render(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	color;
	
	if (cub3d->blood.is_rendering)
	{
		cub3d->blood.time += cub3d->d_time;
		i = -1;
		while (++i < HEIGHT)
		{
			j = -1;
			while (++j < WIDTH)
			{
				color = get_pixel(cub3d->blood.blood_texture.img, j, i);
				put_pixel(&cub3d->img, j, i, color);
			}
		}
	}
	if (cub3d->blood.time > BLOOD_SPLATTER_DURATION)
	{
		cub3d->blood.is_rendering = 0;
		cub3d->blood.time = 0;
	}
}