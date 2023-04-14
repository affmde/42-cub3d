/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:30:22 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/14 14:48:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_cub3d *cub3d)
{
	cub3d->camera->player_angle += 5;
	if (cub3d->camera->player_angle > 360)
		cub3d->camera->player_angle = 0;
}

void	turn_left(t_cub3d *cub3d)
{
	cub3d->camera->player_angle -= 5;
	if (cub3d->camera->player_angle < 0)
		cub3d->camera->player_angle = 360;
}

void	move_forward(t_cub3d *cub3d)
{
	float	player_cos;
	float	player_sin;
	float	new_x;
	float	new_y;

	player_cos = cos(degrees_to_radians(cub3d->camera->player_angle)) * 0.1;
	player_sin = sin(degrees_to_radians(cub3d->camera->player_angle)) * 0.1;
	new_x = cub3d->camera->x + player_cos;
	new_y = cub3d->camera->y + player_sin;
	if (cub3d->map->map[(int)new_y / scale][(int)new_x / scale] == '1')
		return ;
	cub3d->camera->x += player_cos;
	cub3d->camera->y += player_sin;
}

void	move_backwards(t_cub3d *cub3d)
{
	float	player_cos;
	float	player_sin;
	float	new_x;
	float	new_y;

	player_cos = cos(degrees_to_radians(cub3d->camera->player_angle)) * 0.1;
	player_sin = sin(degrees_to_radians(cub3d->camera->player_angle)) * 0.1;
	new_x = cub3d->camera->x - player_cos;
	new_y = cub3d->camera->y - player_sin;
	if (cub3d->map->map[(int)floor(new_y / scale)][(int)floor(new_x / scale)] == '1')
		return ;
	cub3d->camera->x -= player_cos;
	cub3d->camera->y -= player_sin;

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
