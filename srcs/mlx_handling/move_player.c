/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:14:59 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/17 08:36:04 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_cub3d *cub3d)
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

static void	move_backwards(t_cub3d *cub3d)
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

static void	move_left(t_cub3d *cub3d)
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

static void	move_right(t_cub3d *cub3d)
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

void	move_player(t_cub3d *cub3d, int keycode)
{
	if (keycode == 119 || keycode == 126)
		move_forward(cub3d);
	else if (keycode == 115 || keycode == 125)
		move_backwards(cub3d);
	else if (keycode == 97)
		move_left(cub3d);
	else if (keycode == 100)
		move_right(cub3d);
	refresh_window(cub3d);
}