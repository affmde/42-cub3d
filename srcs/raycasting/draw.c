/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:03:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/12 15:07:37 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw(t_cub3d *cub3d)
{
	t_img	*img;
	t_ray	ray;
	int		i;

	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	cub3d->img = img;
	//draw_minimap(cub3d, img);
	i = -1;
	while (++i < WIDTH)
	{
		ray.angle = cub3d->camera->player_angle - cub3d->camera->half_fov + (i * cub3d->camera->angle_increment);
		ray.index = i;
		draw_column(cub3d, &ray);
	//	raycasting(cub3d, &ray);
	//	draw_ray(cub3d, img, &ray);
	//	draw_col(cub3d, &ray);
	}
	//exit(37);
	mlx_put_image_to_window(cub3d->ptr, cub3d->win, img->img_ptr, 0, 0);
}
