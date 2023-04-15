/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:30:22 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/15 12:11:21 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_cub3d *cub3d)
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

void	turn_left(t_cub3d *cub3d)
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

void	move_forward(t_cub3d *cub3d)
{
	int		x;
	int		y;

	y = (int)cub3d->camera->y;
	x = (int)(cub3d->camera->x + cub3d->camera->dir_x * TEST_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->x += cub3d->camera->dir_x * MOVEMENT_SPEED;
	x = (int)cub3d->camera->x;
	y = (int)(cub3d->camera->y + cub3d->camera->dir_y * TEST_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->y += cub3d->camera->dir_y * MOVEMENT_SPEED;
}

void	move_backwards(t_cub3d *cub3d)
{
	int		x;
	int		y;

	y = (int)cub3d->camera->y;
	x = (int)(cub3d->camera->x - cub3d->camera->dir_x * TEST_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->x -= cub3d->camera->dir_x * MOVEMENT_SPEED;
	x = (int)cub3d->camera->x;
	y = (int)(cub3d->camera->y - cub3d->camera->dir_y * TEST_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->y -= cub3d->camera->dir_y * MOVEMENT_SPEED;
}

void	move_left(t_cub3d *cub3d)
{
	int		x;
	int		y;

	y = (int)cub3d->camera->y;
	x = (int)(cub3d->camera->x - cub3d->camera->plane_x * TEST_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->x -= cub3d->camera->plane_x * MOVEMENT_SPEED;
	y = (int)(cub3d->camera->y - cub3d->camera->plane_x * TEST_SPEED);
	x = (int)cub3d->camera->x;
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->y -= cub3d->camera->plane_y * MOVEMENT_SPEED;
}

void	move_right(t_cub3d *cub3d)
{
	int		x;
	int		y;

	y = (int)cub3d->camera->y;
	x = (int)(cub3d->camera->x + cub3d->camera->plane_x * TEST_SPEED);
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->x += cub3d->camera->plane_x * MOVEMENT_SPEED;
	y = (int)(cub3d->camera->y + cub3d->camera->plane_x * TEST_SPEED);
	x = (int)cub3d->camera->x;
	if (cub3d->map->map[y][x] != '1')
		cub3d->camera->y += cub3d->camera->plane_y * MOVEMENT_SPEED;
}

int	deal_key(int keycode, t_cub3d *cub3d)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(cub3d->ptr, cub3d->win);
		exit (1);
	}
	else if (keycode == 119 || keycode == 126)
		move_forward(cub3d);
	else if (keycode == 115 || keycode == 125)
		move_backwards(cub3d);
	else if (keycode == 97)
		move_left(cub3d);
	else if (keycode == 100)
		move_right(cub3d);
	else if (keycode == 65363 || keycode == 124)
		turn_right(cub3d);
	else if (keycode == 65361 || keycode == 123)
		turn_left(cub3d);
	refresh_window(cub3d);
	return (0);
}
