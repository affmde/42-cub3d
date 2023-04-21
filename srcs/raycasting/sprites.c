/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:18:03 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/21 09:33:48 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_sprite_dimensions(t_sprites_manager *s_man)
{
	s_man->sprite_height = abs((int)(HEIGHT / s_man->transform_y));
	s_man->start_y = -s_man->sprite_height + HEIGHT / 2;
	if (s_man->start_y < 0)
		s_man->start_y = 0;
	s_man->end_y = s_man->sprite_height / 2 + HEIGHT / 2;
	if (s_man->end_y > HEIGHT)
		s_man->end_y = HEIGHT - 1;
	s_man->sprite_width = abs((int)(WIDTH / s_man->transform_x));
	s_man->start_x = -s_man->sprite_width / 2 + s_man->sprite_screen_x;
	if (s_man->start_x < 0)
		s_man->start_x = 0;
	s_man->end_x = s_man->sprite_width / 2 + s_man->sprite_screen_x;
	if (s_man->end_x > WIDTH)
		s_man->end_x = WIDTH - 1;
	return ;
}

void	draw_sprite(t_cub3d *cub3d, t_sprites_manager *s_man)
{
	int	x;
	int	i;
	int	tex_x;
	int	tex_y;
	int	color;
	int	d;
	
	x = s_man->start_x;
	while (x < s_man->end_x)
	{
		tex_x = (int)((256 * (x - (-s_man->sprite_width / 2 + s_man->sprite_screen_x)) * s_man->sprite_texture.width / s_man->sprite_width) / 256);
		if (s_man->transform_y > 0 && x > 0 && x < WIDTH && s_man->transform_y < cub3d->z_buffer[x])
		{
			i = s_man->start_y;
			while (i < s_man->end_y)
			{
				d = i * 256 - HEIGHT * 128 + s_man->sprite_height * 128;
				tex_y = ((d / s_man->sprite_texture.height) / s_man->sprite_height) / 256;
				color = s_man->sprite_texture.img->data[s_man->sprite_texture.width * tex_y + tex_x];
				put_pixel(&cub3d->img, x, i, color);
				i++;
			}
		}
		x++;
	}
}

void	project_sprites(t_cub3d *cub3d)
{
	
	t_list				*tmp;
	t_sprites_manager	*s_man;
	t_sprite			*sprite;
	
	s_man = &cub3d->sp_manager;
	tmp = cub3d->sp_manager.sprites_list;
	while (tmp)
	{
		sprite = tmp->content;
		s_man->sprite_x = sprite->x - cub3d->camera.x;
		s_man->sprite_y = sprite->y  - cub3d->camera.y;
		s_man->inv_det = 1.0 / (cub3d->camera.plane_x * cub3d->camera.dir_y - cub3d->camera.dir_x * cub3d->camera.plane_y);
		s_man->transform_x = s_man->inv_det * (cub3d->camera.dir_y * s_man->sprite_x - cub3d->camera.dir_x * s_man->sprite_y);
		s_man->transform_y = s_man->inv_det * (-cub3d->camera.plane_y * s_man->sprite_x + cub3d->camera.plane_x * s_man->sprite_y);
		s_man->sprite_screen_x = (int)((WIDTH / 2) * (1 + s_man->transform_x / s_man->transform_y));
		calculate_sprite_dimensions(s_man);
		draw_sprite(cub3d, s_man);
		tmp = tmp->next;
	}

}
