/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:24:40 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 15:36:48 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	lost_screen(t_cub3d * cub3d)
{
	mlx_clear_window(cub3d->ptr, cub3d->win);
	mlx_string_put(cub3d->ptr, cub3d->win, WIDTH / 2, HEIGHT / 2, 0xffffff, "You Lost!");
	mlx_string_put(cub3d->ptr, cub3d->win, WIDTH / 2, HEIGHT / 2 + 50, 0xffffff, "Press ESC to quit");
}
