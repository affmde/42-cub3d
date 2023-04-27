/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:57 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/27 14:35:55 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	load_gun_texure(t_cub3d *cub3d, char *path, int i)
{
	cub3d->weapon.gun[i].img = ft_calloc(1, sizeof(t_img));
	if (!cub3d->weapon.gun[i].img)
		error_msg_exit("couldn't create the gun sprite");
	cub3d->weapon.gun[i].img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr, path,
			&cub3d->weapon.gun[i].width, &cub3d->weapon.gun[i].height);
	cub3d->weapon.gun[i].img->data = (int *)mlx_get_data_addr(cub3d
			->weapon.gun[i].img->img_ptr,
			&cub3d->weapon.gun[i].img->bpp,
			&cub3d->weapon.gun[i].img->size_l, &cub3d
			->weapon.gun[i].img->endian);
}

void	weapon_init(t_cub3d *cub3d)
{
	load_gun_texure(cub3d, "./textures/shoot0.xpm", 0);
	load_gun_texure(cub3d, "./textures/shoot1.xpm", 1);
	load_gun_texure(cub3d, "./textures/shoot2.xpm", 2);
	load_gun_texure(cub3d, "./textures/shoot3.xpm", 3);
	load_gun_texure(cub3d, "./textures/shoot4.xpm", 4);
	load_gun_texure(cub3d, "./textures/shoot5.xpm", 5);
	load_gun_texure(cub3d, "./textures/shoot6.xpm", 6);
	load_gun_texure(cub3d, "./textures/shoot7.xpm", 7);
	load_gun_texure(cub3d, "./textures/shoot8.xpm", 8);
	load_gun_texure(cub3d, "./textures/shoot9.xpm", 9);
	if (cub3d->sp_manager.total_sprites > 0)
	{
		cub3d->weapon.bullets = cub3d->sp_manager.total_sprites * 2;
		cub3d->weapon.max_bullets = cub3d->sp_manager.total_sprites * 2;
	}
	else
	{
		cub3d->weapon.bullets = 10;
		cub3d->weapon.max_bullets = 10;
	}
	cub3d->weapon.state = 0;
}

void	gun_render(t_cub3d *cub3d, int nbr)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < cub3d->weapon.gun[nbr].height)
	{
		j = 0;
		while (j < cub3d->weapon.gun[nbr].width)
		{
			color = get_pixel(cub3d->weapon.gun[nbr].img, j, i);
			put_pixel(&cub3d->img, WIDTH / 2 - cub3d->weapon.gun[nbr].width
				/ 2 + j, HEIGHT - cub3d->weapon.gun[nbr].height + i, color);
			j++;
		}
		i++;
	}
}

static int	reload_gun(t_cub3d *cub3d, t_weapon *w)
{
	w->anim_frame += cub3d->d_time;
	if (w->anim_frame < RELOAD_TIME * 0.15)
		return (3);
	if (w->anim_frame < RELOAD_TIME * 0.30)
		return (4);
	if (w->anim_frame < RELOAD_TIME * 0.45)
		return (5);
	if (w->anim_frame < RELOAD_TIME * 0.60)
		return (6);
	if (w->anim_frame < RELOAD_TIME * 0.75)
		return (7);
	if (w->anim_frame < RELOAD_TIME * 0.90)
		return (8);
	if (w->anim_frame < RELOAD_TIME)
		return (10);
	else
	{
		w->anim_frame = 0;
		w->state = 0;
		return (0);
	}
}

int	select_gun_texture(t_cub3d *cub3d, t_weapon *w)
{
	if (w->state == 0)
		return (0);
	if (w->state == 1)
	{
		w->anim_frame += cub3d->d_time;
		if (w->anim_frame < FRAME_RATE * 0.5)
			return (1);
		else if (w->anim_frame < FRAME_RATE)
			return (2);
		else
		{
			w->anim_frame = 0;
			w->state = 2;
			return (0);
		}
	}
	if (w->state == 2)
		return (reload_gun(cub3d, w));
	return(0);
}
