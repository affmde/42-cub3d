/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blood_splatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:53:27 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/26 13:32:16 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"


static char	*get_path(int i)
{
	if (i == 0)
		return ("./textures/blood_splatter.xpm");
	if (i == 1)
		return ("./textures/blood_splatter2.xpm");
	if (i == 2)
		return ("./textures/blood_splatter3.xpm");
	return(NULL);

}
static void	load_img(t_cub3d *cub3d, int i)
{
	cub3d->blood.blood_texture[i].img = ft_calloc(1, sizeof(t_img));
	if (!cub3d->blood.blood_texture[i].img)
		error_msg_exit("couldn't load blood splatter texture");
	cub3d->blood.blood_texture[i].img->img_ptr = mlx_xpm_file_to_image(
			cub3d->ptr, get_path(i),
			&cub3d->blood.blood_texture[i].width,
			&cub3d->blood.blood_texture[i].height);
	if (!cub3d->blood.blood_texture[i].img->img_ptr)
		error_msg_exit("couldn't load blood splatter texture");
	cub3d->blood.blood_texture[i].img->data = (int *)mlx_get_data_addr(cub3d
			->blood.blood_texture[i].img->img_ptr,
			&cub3d->blood.blood_texture[i].img->bpp,
			&cub3d->blood.blood_texture[i].img->size_l,
			&cub3d->blood.blood_texture[i].img->endian);
	if (!cub3d->blood.blood_texture[i].img->data)
		error_msg_exit("couldn't load blood splatter texture");
	cub3d->blood.is_rendering = 0;
	cub3d->blood.time = 0;
}

void	blood_splatter_texture(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (++i < 3)
		load_img(cub3d, i);
}

static int	get_blood_index(t_cub3d *cub3d)
{
	if (cub3d->health > 40)
		return (2);
	if (cub3d->health > 10)
		return (1);
	else
		return(0);
}

void	blood_splatter_render(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	color;
	int	index;

	index = get_blood_index(cub3d);
	if (cub3d->blood.is_rendering)
	{
		cub3d->blood.time += cub3d->d_time;
		i = -1;
		while (++i < cub3d->blood.blood_texture[index].height)
		{
			j = -1;
			while (++j < cub3d->blood.blood_texture[index].width)
			{
				color = get_pixel(cub3d->blood.blood_texture[index].img, j, i);
				put_pixel(&cub3d->img, WIDTH - cub3d->blood.blood_texture[index].width + j,
					i, color);
			}
		}
	}
	if (cub3d->blood.time > BLOOD_SPLATTER_DURATION)
	{
		cub3d->blood.is_rendering = 0;
		cub3d->blood.time = 0;
	}
}
