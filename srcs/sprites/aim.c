/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:40:48 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/23 18:17:07 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_aim_texture(t_cub3d *cub3d)
{
	cub3d->aim.img = ft_calloc(1, sizeof(t_textures));
	if (!cub3d->aim.img)
		error_msg_exit("couldn't load the aim image");
	cub3d->aim.img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr, \
	"textures/aim.xpm", &cub3d->aim.width, &cub3d->aim.height);
	if (!cub3d->aim.img->img_ptr)
		error_msg_exit("couldn't load the aim image");
	cub3d->aim.img->data = (int *)mlx_get_data_addr(cub3d->aim.img->img_ptr, \
	&cub3d->aim.img->bpp, &cub3d->aim.img->size_l,
			&cub3d->aim.img->endian);
	if (!cub3d->aim.img->data)
		error_msg_exit("couldn't load the aim image");
}

void	aim_render(t_cub3d *cub3d)
{
	// int		i;
	// int		j;
	t_pos	start;
	t_pos	end;
	//int	color;
	start = populate_position(WIDTH / 2 - CH_MID, HEIGHT / 2, 0, CH_COLOR);
	end = populate_position(WIDTH / 2 - CH_MID \
	- CH_LEN, HEIGHT / 2, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);
	start = populate_position(WIDTH / 2 + CH_MID, HEIGHT / 2, 0, CH_COLOR);
	end = populate_position(WIDTH / 2 + CH_MID \
	+ CH_LEN, HEIGHT / 2, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);
	start = populate_position(WIDTH / 2, HEIGHT / 2 - CH_MID, 0, CH_COLOR);
	end = populate_position(WIDTH / 2, HEIGHT \
	/ 2 - CH_MID - CH_LEN, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);
	start = populate_position(WIDTH / 2, HEIGHT / 2 + CH_MID, 0, CH_COLOR);
	end = populate_position(WIDTH / 2, HEIGHT \
	/ 2 + CH_MID + CH_LEN, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);

	// i = -1;
	// while (++i < cub3d->aim.height)
	// {
	// 	j = -1;
	// 	while (++j < cub3d->aim.width)
	// 	{
	// 		color = get_pixel(cub3d->aim.img, j, i);
	// 		put_pixel(&cub3d->img, WIDTH / 2 - cub3d->aim.width + j / 2, HEIGHT / 2 - cub3d->aim.height / 2 + i, color);
	// 	}
	// }
}