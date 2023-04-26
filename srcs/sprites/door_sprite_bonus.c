/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:39:54 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/26 17:27:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	door_open_text(t_sprite *sprite)
{
	if (sprite->anim_frame < DOOR_SPEED * 0.25)
		return (14);
	if (sprite->anim_frame < DOOR_SPEED * 0.5)
		return (13);
	if (sprite->anim_frame < DOOR_SPEED * 0.75)
		return (12);
	if (sprite->anim_frame < DOOR_SPEED)
		return (11);
	return (16);
}

int	get_door_text(t_cub3d *cub3d, t_sprite *sprite)
{
	if (sprite->hit)
		sprite->anim_frame += cub3d->d_time;
	if (sprite->anim_frame == 0)
		return (16 - sprite->open);
	if (!sprite->open)
		return (door_open_text(sprite));
	if (sprite->anim_frame < DOOR_SPEED * 0.25)
		return (11);
	if (sprite->anim_frame < DOOR_SPEED * 0.5)
		return (12);
	if (sprite->anim_frame < DOOR_SPEED * 0.75)
		return (13);
	if (sprite->anim_frame < DOOR_SPEED)
		return (14);
	return (15);
}
