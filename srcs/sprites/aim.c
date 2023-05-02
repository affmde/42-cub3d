/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:40:48 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 15:51:46 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	aim_render(t_cub3d *cub3d)
{
	t_pos	start;
	t_pos	end;

	start = populate_position(WIDTH / 2 - CH_MID, HEIGHT / 2, 0, CH_COLOR);
	end = populate_position(WIDTH / 2 - CH_MID \
	- CH_LEN, HEIGHT / 2, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);
	start = populate_position(WIDTH / 2 + CH_MID, HEIGHT / 2, 0, CH_COLOR);
	end = populate_position(WIDTH / 2 + CH_MID \
	+ CH_LEN, HEIGHT / 2, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);
	start = populate_position(WIDTH / 2, HEIGHT / 2 - CH_MID, 0, CH_COLOR);
	end = populate_position(WIDTH / 2, HEIGHT \
	/ 2 - CH_MID - CH_LEN, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);
	start = populate_position(WIDTH / 2, HEIGHT / 2 + CH_MID, 0, CH_COLOR);
	end = populate_position(WIDTH / 2, HEIGHT \
	/ 2 + CH_MID + CH_LEN, 0, CH_COLOR);
	bresenham_algo(start, end, &cub3d->img);
}
