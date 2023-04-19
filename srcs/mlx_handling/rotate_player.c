/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:29:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/19 15:56:29 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn_right(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane;

	old_dir_x = cub3d->camera.dir_x;
	cub3d->camera.dir_x = cub3d->camera.dir_x * cos(ROTATE_SPEED)
		- cub3d->camera.dir_y * sin(ROTATE_SPEED);
	cub3d->camera.dir_y = old_dir_x * sin(ROTATE_SPEED)
		+ cub3d->camera.dir_y * cos(ROTATE_SPEED);
	old_plane = cub3d->camera.plane_x;
	cub3d->camera.plane_x = cub3d->camera.plane_x * cos(ROTATE_SPEED)
		- cub3d->camera.plane_y * sin(ROTATE_SPEED);
	cub3d->camera.plane_y = old_plane * sin(ROTATE_SPEED)
		+ cub3d->camera.plane_y * cos(ROTATE_SPEED);
}

static void	turn_left(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane;

	old_dir_x = cub3d->camera.dir_x;
	cub3d->camera.dir_x = cub3d->camera.dir_x * cos(-ROTATE_SPEED)
		- cub3d->camera.dir_y * sin(-ROTATE_SPEED);
	cub3d->camera.dir_y = old_dir_x * sin(-ROTATE_SPEED)
		+ cub3d->camera.dir_y * cos(-ROTATE_SPEED);
	old_plane = cub3d->camera.plane_x;
	cub3d->camera.plane_x = cub3d->camera.plane_x * cos(-ROTATE_SPEED)
		- cub3d->camera.plane_y * sin(-ROTATE_SPEED);
	cub3d->camera.plane_y = old_plane * sin(-ROTATE_SPEED)
		+ cub3d->camera.plane_y * cos(-ROTATE_SPEED);
}

void	rotate_player(t_cub3d *cub3d)
{
	if (cub3d->movement.turn_right)
		turn_right(cub3d);
	else if (cub3d->movement.turn_left)
		turn_left(cub3d);
}
