/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:55:16 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 15:11:26 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	draw_inner_bar(t_cub3d *cub3d)
{
	int	i;
	int j;

	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < cub3d->weapon.max_bullets * cub3d->weapon.b_text.width)
		{
			put_pixel(&cub3d->img, cub3d->weapon.b_text.width + j, HEIGHT - (cub3d->weapon.b_text.height * 2) + i , 0xff0000);
		}
	}
}
static void	draw_life_bar(t_cub3d *cub3d)
{
	int	i;
	int j;
	int	bar_width;

	bar_width = cub3d->weapon.max_bullets * cub3d->weapon.b_text.width * cub3d->health / 100;
	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < bar_width)
		{
			put_pixel(&cub3d->img, cub3d->weapon.b_text.width + j, HEIGHT - (cub3d->weapon.b_text.height * 2) + i , 0x00ff00);
		}
	}
}

void	draw_health_bar(t_cub3d *cub3d)
{
	if (cub3d->health > 0)
	{
		draw_inner_bar(cub3d);
		draw_life_bar(cub3d);
	}
}
