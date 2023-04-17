/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:30:22 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/17 11:22:58 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	deal_key(int keycode, t_cub3d *cub3d)
{
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(cub3d->ptr, cub3d->win);
		exit (1);
	}
	else if (keycode == 65363 || keycode == 124
		|| keycode == 65361 || keycode == 123)
		rotate_player(cub3d, keycode);
	else
		move_player(cub3d, keycode);
	return (0);
}
