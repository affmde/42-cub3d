/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:35:01 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 18:13:17 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	close_window(void)
{
	exit(0);
}

static void	data_update(t_cub3d *cub3d)
{
	delta_time(cub3d);
	cub3d->total_time += cub3d->d_time;
}

static int	play(t_cub3d *cub3d)
{
	if (cub3d->health > 0 && !cub3d->won)
	{
		data_update(cub3d);
		raycast_environemt(cub3d);
		move_player(cub3d);
		rotate_player(cub3d);
	}
	else if (cub3d->health <= 0 && cub3d->sp_manager.enemies_left > 0)
		end_screen(cub3d, "You lost");
	else if (cub3d->won)
		end_screen(cub3d, "You won!! Congrats");
	return (0);
}

static double	*z_buffer_creator(void)
{
	double	*buffer;

	buffer = (double *)malloc(sizeof(double) * WIDTH);
	if (!buffer)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd("Couldn't create buffer for sprites", 2);
		exit (1);
	}
	return (buffer);
}

int	mlx_handling(t_cub3d *cub3d)
{
	cub3d->mouse_x = -1;
	cub3d->ptr = mlx_init();
	if (load_textures(cub3d))
		exit(1);
	cub3d->win = mlx_new_window(cub3d->ptr, WIDTH, HEIGHT, "cub3d");
	image_init(cub3d);
	cub3d->z_buffer = z_buffer_creator();
	load_all_bonus_tex(cub3d);
	mlx_loop_hook(cub3d->ptr, &play, cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, &handle_key_pressed, cub3d);
	mlx_hook(cub3d->win, 3, 1L << 1, &handle_key_released, cub3d);
	mlx_hook(cub3d->win, 17, 0, close_window, NULL);
	mlx_hook(cub3d->win, 6, 1L << 0, &mouse, cub3d);
	mlx_loop(cub3d->ptr);
	return (0);
}
