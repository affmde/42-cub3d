/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullets_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:04:28 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 16:04:42 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	load_bullet_texture(t_cub3d *cub3d)
{
	cub3d->weapon.b_text.img = ft_calloc(1, sizeof(t_img));
	if (!cub3d->weapon.b_text.img)
		error_msg_exit("couldn't load bullets texture");
	cub3d->weapon.b_text.img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr,
			"./textures/bullet.xpm", &cub3d->weapon.b_text.width,
			&cub3d->weapon.b_text.height);
	if (!cub3d->weapon.b_text.img->img_ptr)
		error_msg_exit("couldn't load bullets texture");
	cub3d->weapon.b_text.img->data = (int *)mlx_get_data_addr(cub3d
			->weapon.b_text.img->img_ptr,
			&cub3d->weapon.b_text.img->bpp, &cub3d->weapon.b_text.img->size_l,
			&cub3d->weapon.b_text.img->endian);
	if (!cub3d->weapon.b_text.img->data)
		error_msg_exit("couldn't load bullets texture");
}

void	bullets_render(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	k;
	int	color;

	k = -1;
	while (++k < cub3d->weapon.bullets)
	{
		i = -1;
		while (++i < cub3d->weapon.b_text.height)
		{
			j = -1;
			while (++j < cub3d->weapon.b_text.width)
			{
				color = get_pixel(cub3d->weapon.b_text.img, j, i);
				put_pixel(&cub3d->img, 20 + k * cub3d->weapon.b_text.width
					+ j, HEIGHT - cub3d->weapon.b_text.height + i, color);
			}
		}
	}
}
