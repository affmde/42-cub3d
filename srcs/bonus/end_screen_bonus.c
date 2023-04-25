/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:10:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 16:10:53 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	end_screen(t_cub3d *cub3d, char * message)
{
	mlx_clear_window(cub3d->ptr, cub3d->win);
	mlx_string_put(cub3d->ptr, cub3d->win, WIDTH / 2, HEIGHT / 2, 0xffffff, message);
	mlx_string_put(cub3d->ptr, cub3d->win, WIDTH / 2, HEIGHT / 2 + 50, 0xffffff, "Press ESC to quit");
}
