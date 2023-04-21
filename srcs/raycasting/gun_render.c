/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:57 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/21 17:02:19 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	transfer_pixels(t_cub3d *cub3d)
// {
// 	int	i;
// 	int	j;
// 	int offset;
// 	int	color;

// 	i = 0;
// 	while (i < cub3d->sp_manager.gun.height)
// 	{
// 		j = 0;
// 		while (j < cub3d->sp_manager.gun.width)
// 		{
// 			offset = i * (cub3d->sp_manager.gun.img->size_l >> 2) + j;
// 			color = cub3d->sp_manager.gun.img->data[offset];
// 			put_pixel(&cub3d->img, WIDTH / 2 - 64 + j, HEIGHT - 128 + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void load_gun_texure(t_cub3d *cub3d)
{
	cub3d->sp_manager.gun.img = ft_calloc(1, sizeof(t_img));
	if (!cub3d->sp_manager.gun.img)
		error_msg_exit("couldn't create the gun sprite");
	cub3d->sp_manager.gun.img->img_ptr = mlx_xpm_file_to_image(cub3d->ptr, "./textures/gun.xpm", &cub3d->sp_manager.gun.height, &cub3d->sp_manager.gun.width);
	cub3d->sp_manager.gun.img->data =
		(int *)mlx_get_data_addr(cub3d->sp_manager.gun.img->img_ptr,
		&cub3d->sp_manager.gun.img->bpp,
		&cub3d->sp_manager.gun.img->size_l, &cub3d->sp_manager.gun.img->endian);
}

void	gun_render(t_cub3d *cub3d)
{
	int	i;
	int	j;
	//int offset;
	int	color;

	i = 0;
	while (i < cub3d->sp_manager.gun.height)
	{
		j = 0;
		while (j < cub3d->sp_manager.gun.width)
		{
			//offset = i * (cub3d->sp_manager.gun.img->size_l >> 2) + j;
			color = get_pixel(cub3d->sp_manager.gun.img, j, i);
			put_pixel(&cub3d->img, WIDTH / 2 - 64 + j, HEIGHT - 128 + i, color);
			j++;
		}
		i++;
	}
}
