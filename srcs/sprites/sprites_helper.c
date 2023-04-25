/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:18:25 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 17:40:26 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	draw_sprite_loop(t_cub3d *cub3d, t_sprite *sprite, int tex_x, int x)
{
	int					tex_y;
	int					i;
	int					d;
	t_sprites_manager	*s_man;

	s_man = &cub3d->sp_manager;
	i = s_man->start_y;
	while (i < s_man->end_y)
	{
		d = i * 256 - HEIGHT * 128
			+ s_man->sprite_height * 128;
		tex_y = ((d * s_man->sprite_texture[sprite->texture].height)
				/ s_man->sprite_height) / 256;
		s_man->color = s_man->sprite_texture[sprite->texture].img
			->data[s_man->sprite_texture[sprite->texture].width
			* tex_y + tex_x];
		if ((s_man->color & 0x00FFFFFF) != 0)
			put_pixel(&cub3d->img, x, i, s_man->color);
		i++;
	}
}

void	handle_sprite_alive(t_cub3d *cub3d, t_sprite *sprite)
{
	t_sprites_manager	*s_man;

	s_man = &cub3d->sp_manager;
	s_man->sprite_x = sprite->x - cub3d->camera.x;
	s_man->sprite_y = sprite->y - cub3d->camera.y;
	s_man->inv_det = 1.0 / (cub3d->camera.plane_x * cub3d->camera.dir_y
			- cub3d->camera.dir_x * cub3d->camera.plane_y);
	s_man->transform_x = s_man->inv_det * (cub3d->camera.dir_y
			* s_man->sprite_x - cub3d->camera.dir_x * s_man->sprite_y);
	s_man->transform_y = s_man->inv_det * (-cub3d->camera.plane_y
			* s_man->sprite_x + cub3d->camera.plane_x
			* s_man->sprite_y);
	s_man->sprite_screen_x = (int)((WIDTH / 2)
			* (1 + s_man->transform_x / s_man->transform_y));
}
