/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:30:22 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/14 15:57:13 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane;

	old_dir_x = cub3d->camera->dir_x;
	cub3d->camera->dir_x = cub3d->camera->dir_x * cos(-ROTATE_SPEED) - cub3d->camera->dir_y * sin(-ROTATE_SPEED);
	cub3d->camera->dir_y = old_dir_x * sin(-ROTATE_SPEED) + cub3d->camera->dir_y * cos(-ROTATE_SPEED);
	old_plane = cub3d->camera->plane_x;
	cub3d->camera->plane_x = cub3d->camera->plane_x * cos(-ROTATE_SPEED) - cub3d->camera->plane_y * sin(-ROTATE_SPEED);
	cub3d->camera->plane_y = old_plane * sin(-ROTATE_SPEED) + cub3d->camera->plane_y * cos(-ROTATE_SPEED);
}

void	turn_left(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane;

	old_dir_x = cub3d->camera->dir_x;
	cub3d->camera->dir_x = cub3d->camera->dir_x * cos(ROTATE_SPEED) - cub3d->camera->dir_y * sin(ROTATE_SPEED);
	cub3d->camera->dir_y = old_dir_x * sin(ROTATE_SPEED) + cub3d->camera->dir_y * cos(ROTATE_SPEED);
	old_plane = cub3d->camera->plane_x;
	cub3d->camera->plane_x = cub3d->camera->plane_x * cos(ROTATE_SPEED) - cub3d->camera->plane_y * sin(ROTATE_SPEED);
	cub3d->camera->plane_y = old_plane * sin(ROTATE_SPEED) + cub3d->camera->plane_y * cos(ROTATE_SPEED);
}

void	move_forward(t_cub3d *cub3d)
{
	int		x;
	int		y;

	y = (int)cub3d->camera->y;
	x = (int)(cub3d->camera->x + cub3d->camera->dir_x * MOVEMENT_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->x += cub3d->camera->dir_x * MOVEMENT_SPEED;
	x = (int)cub3d->camera->x;
	y = (int)(cub3d->camera->y + cub3d->camera->dir_y * MOVEMENT_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->y += cub3d->camera->dir_y * MOVEMENT_SPEED;
}

void	move_backwards(t_cub3d *cub3d)
{
	int		x;
	int		y;

	y = (int)cub3d->camera->y;
	x = (int)(cub3d->camera->x - cub3d->camera->dir_x * MOVEMENT_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->x -= cub3d->camera->dir_x * MOVEMENT_SPEED;
	x = (int)cub3d->camera->x;
	y = (int)(cub3d->camera->y - cub3d->camera->dir_y * MOVEMENT_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->y -= cub3d->camera->dir_y * MOVEMENT_SPEED;
}

int	deal_key(int keycode, t_cub3d *cub3d)
{
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(cub3d->ptr, cub3d->win);
		exit (1);
	}
	else if (keycode == 65362 || keycode == 126)
		move_forward(cub3d);
	else if (keycode == 65363 || keycode == 124)
		turn_right(cub3d);
	else if (keycode == 65364 || keycode == 125)
		move_backwards(cub3d);
	else if (keycode == 65361 || keycode == 123)
		turn_left(cub3d);
	refresh_window(cub3d);
	return (0);
}
