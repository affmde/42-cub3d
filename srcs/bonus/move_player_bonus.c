/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/24 18:12:37 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	move_forward(t_cub3d *cub3d)
{
	int		x;
	int		y;
	double	player_body;

	if (cub3d->camera.dir_x > 0)
		player_body = PLAYER_BODY;
	else
		player_body = -PLAYER_BODY;
	y = (int)cub3d->camera.y;
	x = (int)(cub3d->camera.x + cub3d->camera.dir_x
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.x += cub3d->camera.dir_x * (MOVEMENT_SPEED * cub3d->d_time);
	if (cub3d->camera.dir_y > 0)
		player_body = PLAYER_BODY;
	else if (cub3d->camera.dir_x > 0)
		player_body = -PLAYER_BODY;
	x = (int)cub3d->camera.x;
	y = (int)(cub3d->camera.y + cub3d->camera.dir_y
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.y += cub3d->camera.dir_y * (MOVEMENT_SPEED * cub3d->d_time);
}

static void	move_backwards(t_cub3d *cub3d)
{
	int		x;
	int		y;
	double	player_body;

	if (cub3d->camera.dir_x > 0)
		player_body = -PLAYER_BODY;
	else
		player_body = PLAYER_BODY;
	y = (int)cub3d->camera.y;
	x = (int)(cub3d->camera.x - cub3d->camera.dir_x
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.x -= cub3d->camera.dir_x * (MOVEMENT_SPEED * cub3d->d_time);
	if (cub3d->camera.dir_y > 0)
		player_body = -PLAYER_BODY;
	else if (cub3d->camera.dir_x > 0)
		player_body = PLAYER_BODY;
	x = (int)cub3d->camera.x;
	y = (int)(cub3d->camera.y - cub3d->camera.dir_y
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.y -= cub3d->camera.dir_y * (MOVEMENT_SPEED * cub3d->d_time);
}

static void	move_left(t_cub3d *cub3d)
{
	int		x;
	int		y;
	double	player_body;

	if (cub3d->camera.plane_x > 0)
		player_body = -PLAYER_BODY;
	else
		player_body = PLAYER_BODY;
	y = (int)cub3d->camera.y;
	x = (int)(cub3d->camera.x - cub3d->camera.plane_x
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.x -= cub3d->camera.plane_x * (MOVEMENT_SPEED * cub3d->d_time);
	if (cub3d->camera.plane_y > 0)
		player_body = -PLAYER_BODY;
	else if (cub3d->camera.plane_x > 0)
		player_body = PLAYER_BODY;
	y = (int)(cub3d->camera.y - cub3d->camera.plane_x
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	x = (int)cub3d->camera.x;
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.y -= cub3d->camera.plane_y * (MOVEMENT_SPEED * cub3d->d_time);
}

static void	move_right(t_cub3d *cub3d)
{
	int		x;
	int		y;
	double	player_body;

	if (cub3d->camera.plane_x > 0)
		player_body = PLAYER_BODY;
	else
		player_body = -PLAYER_BODY;
	y = (int)cub3d->camera.y;
	x = (int)(cub3d->camera.x + cub3d->camera.plane_x
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.x += cub3d->camera.plane_x * (MOVEMENT_SPEED * cub3d->d_time);
	if (cub3d->camera.plane_y > 0)
		player_body = PLAYER_BODY;
	else if (cub3d->camera.plane_x > 0)
		player_body = -PLAYER_BODY;
	y = (int)(cub3d->camera.y + cub3d->camera.plane_x
			* (MOVEMENT_SPEED * cub3d->d_time) + player_body);
	x = (int)cub3d->camera.x;
	if (can_move(cub3d->map->map[y][x]))
		cub3d->camera.y += cub3d->camera.plane_y * (MOVEMENT_SPEED * cub3d->d_time);
}

void	move_player(t_cub3d *cub3d)
{
	if (cub3d->movement.move_forward)
		move_forward(cub3d);
	else if (cub3d->movement.move_backwards)
		move_backwards(cub3d);
	if (cub3d->movement.move_left)
		move_left(cub3d);
	else if (cub3d->movement.move_right)
		move_right(cub3d);
}
