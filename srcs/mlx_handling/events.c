/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:30:22 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/06 19:47:37 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



void	turn_right(t_cub3d *cub3d)
{
	cub3d->camera->player_angle += 5;
	if (cub3d->camera->player_angle > 360)
		cub3d->camera->player_angle = 0;
	refresh_window(cub3d);
}

void	turn_left(t_cub3d *cub3d)
{
	cub3d->camera->player_angle -= 5;
	if (cub3d->camera->player_angle < 0)
		cub3d->camera->player_angle = 360;
	refresh_window(cub3d);
}

void	move_right(t_cub3d *cub3d)
{
	if (cub3d->camera->x < WIDTH - 1)
		cub3d->camera->x += 5;
	refresh_window(cub3d);
}

void	move_left(t_cub3d *cub3d)
{
	if (cub3d->camera->x > 0)
		cub3d->camera->x -= 5;
	refresh_window(cub3d);
}

void	move_up(t_cub3d *cub3d)
{
	if (cub3d->camera->y > 0)
		cub3d->camera->y -= 5;
	refresh_window(cub3d);
}

void	move_down(t_cub3d *cub3d)
{
	if (cub3d->camera->y < HEIGHT - 1)
		cub3d->camera->y += 5;
	refresh_window(cub3d);
}

int	deal_key(int keycode, t_cub3d *cub3d)
{
	//printf("keycode: %d\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(cub3d->ptr, cub3d->win);
		exit (1);
	}
	else if (keycode == 65363)
		turn_right(cub3d);
	else if (keycode == 65361)
		turn_left(cub3d);
	else if (keycode == 119)
		move_up(cub3d);
	else if (keycode == 100)
		move_right(cub3d);
	else if (keycode == 115)
		move_down(cub3d);
	else if (keycode == 97)
		move_left(cub3d);
	return (0);
}