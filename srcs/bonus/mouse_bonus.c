/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:51:17 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/27 13:51:20 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

double	fix_dif(double dif)
{
	if (dif < 0)
		return (0.07);
	else
		return (-0.07);
}

void	new_rotation_values(t_cub3d *cub3d, double x_dif)
{
	double	old_dir_x;
	double	old_plane;

	old_dir_x = cub3d->camera.dir_x;
	cub3d->camera.dir_x = cub3d->camera.dir_x * \
	cos(-x_dif) - cub3d->camera.dir_y * sin(-x_dif);
	cub3d->camera.dir_y = old_dir_x * sin(-x_dif) \
	+ cub3d->camera.dir_y * cos(-x_dif);
	old_plane = cub3d->camera.plane_x;
	cub3d->camera.plane_x = cub3d->camera.plane_x * \
	cos(-x_dif) - cub3d->camera.plane_y * sin(-x_dif);
	cub3d->camera.plane_y = old_plane * sin(-x_dif) \
	+ cub3d->camera.plane_y * cos(-x_dif);
}

int	mouse(int x, int y, t_cub3d *cub3d)
{
	double	x_dif;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return (1);
	if (cub3d->mouse_x == -1)
	{
		cub3d->mouse_x = x;
		return (37);
	}
	x_dif = x - cub3d->mouse_x;
	if (x_dif == 0)
		return (1);
	x_dif = fix_dif(x_dif);
	new_rotation_values(cub3d, x_dif);
	cub3d->mouse_x = x;
	return (0);
}
