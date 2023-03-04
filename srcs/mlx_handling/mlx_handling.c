/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:42:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 15:43:33 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(void)
{
	exit(0);
}

int	mlx_handling(t_cub3d *cub3d)
{
	//t_pos start;
	//t_pos end;
	cub3d->ptr = mlx_init();
	cub3d->win = mlx_new_window(cub3d->ptr, WIDTH, HEIGHT, "My window");
	
	//cub3d->img = ft_calloc(1, sizeof(t_img));
	//cub3d->img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	//cub3d->img->data = (int *)mlx_get_data_addr(cub3d->img->img_ptr, &cub3d->img->bpp, &cub3d->img->size_l, &cub3d->img->endian);
	//start = populate_position(10, 10, 0, create_rgb(get_wall_color("F", cub3d)));
	//end = populate_position(500, 200, 0, create_rgb(get_wall_color("C", cub3d)));
	//bresenham_algo(start, end, cub3d->img);
	//mlx_put_image_to_window(cub3d->ptr, cub3d->win, cub3d->img->img_ptr, 0, 0);
	mlx_key_hook(cub3d->win, deal_key, cub3d);
	mlx_hook(cub3d->win, 17, 0, close_window, NULL);
	mlx_loop(cub3d->ptr);
	return (0);
}