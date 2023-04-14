/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:42:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/14 14:54:11 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(void)
{
	exit(0);
}



int	mlx_handling(t_cub3d *cub3d)
{
	cub3d->ptr = mlx_init();
	if (load_textures(cub3d))
		exit(1);
	cub3d->win = mlx_new_window(cub3d->ptr, WIDTH, HEIGHT, "cub3d");
	mlx_hook(cub3d->win, 2, 1L << 0, &deal_key, cub3d);
	mlx_hook(cub3d->win, 17, 0, close_window, NULL);
	draw(cub3d);
	mlx_loop(cub3d->ptr);
	return (0);
}
