/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:12:15 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/14 15:12:28 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse(int x, int y, t_cub3d *cub3d)
{
	int	x_dif;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return (1);
	if (cub3d->mouse_x == -1)
	{
		cub3d->mouse_x = x;
		return (37);
	}
	x_dif = x - cub3d->mouse_x;
	while (x_dif > 15 || x_dif < -15)
		x_dif = x_dif / 5;
	cub3d->camera->player_angle += x_dif;
	if (cub3d->camera->player_angle < 0)
		cub3d->camera->player_angle = 360;
	cub3d->mouse_x = x;
	refresh_window(cub3d);
	return (1);
}