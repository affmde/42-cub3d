/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:29:06 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/26 12:49:44 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static char	*get_path_door(int i)
{
	if (i == 10)
		return ("./textures/door_open.xpm");
	if (i == 11)
		return ("./textures/door_closing1.xpm");
	if (i == 12)
		return ("./textures/door_closing2.xpm");
	if (i == 13)
		return ("./textures/door_closing3.xpm");
	if (i == 14)
		return ("./textures/door_closing4.xpm");
	if (i == 15)
		return ("./textures/door_closed.xpm");
	return (NULL);
}

static char	*get_path_guard(int i)
{
	if (i == 0)
		return ("./textures/guard.xpm");
	if (i == 1)
		return ("./textures/guard_die1.xpm");
	if (i == 2)
		return ("./textures/guard_die2.xpm");
	if (i == 3)
		return ("./textures/guard_die3.xpm");
	if (i == 4)
		return ("./textures/guard_die4.xpm");
	if (i == 5)
		return ("./textures/guard_die5.xpm");
	if (i == 6)
		return ("./textures/guard_attack1.xpm");
	if (i == 7)
		return ("./textures/guard_attack2.xpm");
	if (i == 8)
		return ("./textures/guard_attack3.xpm");
	if (i == 9)
		return ("./textures/guard_attack4.xpm");
	return (get_path_door(i));
}

void	load_sprite_texture(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		cub3d->sp_manager.sprite_texture[i].img = ft_calloc(1, sizeof(t_img));
		if (!cub3d->sp_manager.sprite_texture[i].img)
			error_msg_exit("couldn't load sprite texture");
		cub3d->sp_manager.sprite_texture[i].img->img_ptr
			= mlx_xpm_file_to_image(cub3d->ptr,
				get_path_guard(i), &cub3d->sp_manager.sprite_texture[i].height,
				&cub3d->sp_manager.sprite_texture[i].width);
		if (!cub3d->sp_manager.sprite_texture[i].img->img_ptr)
			error_msg_exit("couldn't load sprite texture");
		cub3d->sp_manager.sprite_texture[i].img->data
			= (int *)mlx_get_data_addr(cub3d
				->sp_manager.sprite_texture[i].img->img_ptr,
				&cub3d->sp_manager.sprite_texture[i].img->bpp,
				&cub3d->sp_manager.sprite_texture[i].img->size_l,
				&cub3d->sp_manager.sprite_texture[i].img->endian);
		if (!cub3d->sp_manager.sprite_texture[i].img->data)
			error_msg_exit("couldn't load sprite texture");
	}
}
