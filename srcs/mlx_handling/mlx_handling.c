/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:42:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/19 15:59:27 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_window(void)
{
	exit(0);
}

static int	play(t_cub3d *cub3d)
{
	raycasting(cub3d);
	move_player(cub3d);
	rotate_player(cub3d);
	return (0);
}

void	movement_init(t_movement *m)
{
	m->move_backwards = 0;
	m->move_forward = 0;
	m->move_right = 0;
	m->move_left = 0;
	m->turn_left = 0;
	m->turn_right = 0;
}

int	mlx_handling(t_cub3d *cub3d)
{
	cub3d->mouse_x = -1;
	cub3d->ptr = mlx_init();
	if (load_textures(cub3d))
		exit(1);
	cub3d->win = mlx_new_window(cub3d->ptr, WIDTH, HEIGHT, "cub3d");
	image_init(cub3d);
	ray_init(cub3d);
	movement_init(&cub3d->movement);
	mlx_loop_hook(cub3d->ptr, &play, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, &handle_key_pressed, cub3d);
	mlx_hook(cub3d->win, 3, 1L << 1, &handle_key_released, cub3d);
	mlx_hook(cub3d->win, 17, 0, close_window, NULL);
	mlx_hook(cub3d->win, 6, 1L << 0, &mouse, cub3d);
	mlx_loop(cub3d->ptr);
	return (0);
}
