/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:45:08 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/27 07:54:52 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	handle_key_pressed(int keycode, t_cub3d *cub3d)
{
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(cub3d->ptr, cub3d->win);
		exit (0);
	}
	else if (keycode == MAC_UP || keycode == LIN_UP)
		cub3d->movement.move_forward = 1;
	else if (keycode == MAC_DOWN || keycode == LIN_DOWN)
		cub3d->movement.move_backwards = 1;
	else if (keycode == MAC_LEFT || keycode == LIN_LEFT)
		cub3d->movement.move_left = 1;
	else if (keycode == MAC_RIGHT || keycode == LIN_RIGHT)
		cub3d->movement.move_right = 1;
	else if (keycode == MAC_R_RIGHT || keycode == LIN_R_RIGHT)
		cub3d->movement.turn_right = 1;
	else if (keycode == MAC_R_LEFT || keycode == LIN_R_LEFT)
		cub3d->movement.turn_left = 1;
	return (0);
}

int	handle_key_released(int keycode, t_cub3d *cub3d)
{
	if (keycode == MAC_F || keycode == LIN_F)
		raycasting(cub3d, (int)(WIDTH / 2), 2);
	if (keycode == MAC_SPACE || keycode == LIN_SPACE)
		shoot(cub3d);
	if (keycode == MAC_UP || keycode == LIN_UP)
		cub3d->movement.move_forward = 0;
	else if (keycode == MAC_DOWN || keycode == LIN_DOWN)
		cub3d->movement.move_backwards = 0;
	if (keycode == MAC_LEFT || keycode == LIN_LEFT)
		cub3d->movement.move_left = 0;
	else if (keycode == MAC_RIGHT || keycode == LIN_RIGHT)
		cub3d->movement.move_right = 0;
	if (keycode == MAC_R_RIGHT || keycode == LIN_R_RIGHT)
		cub3d->movement.turn_right = 0;
	else if (keycode == MAC_R_LEFT || keycode == LIN_R_LEFT)
		cub3d->movement.turn_left = 0;
	return (0);
}
