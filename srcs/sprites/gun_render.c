/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:57 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 10:05:33 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	allocate_weapon_tex(t_cub3d *cub3d)
{
	cub3d->weapon.gun = ft_calloc(5, sizeof(t_textures));
	if (!cub3d->weapon.gun)
		error_msg_exit("couldn't load weapon textures");
}

static void load_gun_texure(t_cub3d *cub3d, char *path, int i)
{
	cub3d->weapon.gun[i].img = ft_calloc(1, sizeof(t_img));
	if (!cub3d->weapon.gun[i].img)
		error_msg_exit("couldn't create the gun sprite");
	cub3d->weapon.gun[i].img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr, path, 
		&cub3d->weapon.gun[i].width, &cub3d->weapon.gun[i].height);
	cub3d->weapon.gun[i].img->data =
		(int *)mlx_get_data_addr(cub3d->weapon.gun[i].img->img_ptr,
		&cub3d->weapon.gun[i].img->bpp,
		&cub3d->weapon.gun[i].img->size_l, &cub3d->weapon.gun[i].img->endian);
}

void	weapon_init(t_cub3d *cub3d)
{
	allocate_weapon_tex(cub3d);
	load_gun_texure(cub3d, "./textures/shotgun.xpm", 0);
	load_gun_texure(cub3d, "./textures/shotgun2.xpm", 1);
	load_gun_texure(cub3d, "./textures/shotgun3.xpm", 2);
	load_gun_texure(cub3d, "./textures/shotgun4.xpm", 3);
	load_gun_texure(cub3d, "./textures/shotgun5.xpm", 4);
	cub3d->weapon.bullets = 10;
	cub3d->weapon.max_bullets = 10;
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

int	select_gun_texture(t_cub3d *cub3d, t_weapon *w)
{
	if (w->anim_frame > FRAME_RATE)
	{
		w->anim_frame = 0;
		w->state = 0;
	}
	if (w->state == 0)
		return (0);
	else
	{
		w->anim_frame += cub3d->d_time;
		if (w->anim_frame < FRAME_RATE * 0.25)
			return (1);
		else if (w->anim_frame < FRAME_RATE * 0.5)
			return (2);
		else if (w->anim_frame < FRAME_RATE * 0.75)
			return (3);
		else
			return (4);
	}
}
