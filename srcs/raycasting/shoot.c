/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:28:16 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/23 10:31:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	allow_shoot(t_weapon *w)
{
	if (w->anim_frame > 0)
		return (0);
	if (w->bullets < 0 || w->bullets > w->max_bullets)
		return (0);
	return (1);
}

void	shoot(t_cub3d *cub3d)
{
	if (allow_shoot(&cub3d->weapon))
	{
		cub3d->weapon.bullets--;
		cub3d->weapon.state = 1;
		cub3d->weapon.anim_frame++;
	}
}
