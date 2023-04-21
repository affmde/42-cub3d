/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:29:06 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/21 14:32:55 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_sprite_texture(t_cub3d *cub3d)
{
	cub3d->sp_manager.sprite_texture.img = ft_calloc(1, sizeof(t_textures));
	if (!cub3d->sp_manager.sprite_texture.img)
		error_msg_exit("couldn't load sprite texture");
	cub3d->sp_manager.sprite_texture.img->img_ptr
		= mlx_xpm_file_to_image(cub3d->ptr,
			"./textures/enemy.xpm", &cub3d->sp_manager.sprite_texture.height,
			&cub3d->sp_manager.sprite_texture.width);
	if (!cub3d->sp_manager.sprite_texture.img->img_ptr)
		error_msg_exit("couldn't load sprite texture");
	cub3d->sp_manager.sprite_texture.img->data
		= (int*)mlx_get_data_addr(cub3d->sp_manager.sprite_texture.img->img_ptr,
			&cub3d->sp_manager.sprite_texture.img->bpp,
			&cub3d->sp_manager.sprite_texture.img->size_l,
			&cub3d->sp_manager.sprite_texture.img->endian);
	if (!cub3d->sp_manager.sprite_texture.img->data)
		error_msg_exit("couldn't load sprite texture");
}
