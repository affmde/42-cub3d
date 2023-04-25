/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:30:22 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 11:59:47 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	printf("%d\n", keycode);
	if (keycode == MAC_SPACE || keycode == LIN_CTRL)
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
