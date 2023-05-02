/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:32:03 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 16:32:45 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	check_blood_anim_over(t_blood *blood)
{
	if (blood->time > BLOOD_SPLATTER_DURATION)
	{
		blood->is_rendering = 0;
		blood->time = 0;
	}
}

static int	handle_enemy_die_anim_end(t_cub3d *cub3d, t_sprite *sprite)
{
	sprite->alive = 0;
	cub3d->sp_manager.enemies_left--;
	if (cub3d->sp_manager.enemies_left <= 0)
		cub3d->won = 1;
	return (5);
}

int	get_sprite_text(t_cub3d *cub3d, t_sprite *sprite)
{
	if (sprite->identifier != '2')
		return (get_door_text(cub3d, sprite));
	if (sprite->is_attacking && sprite->alive)
		return (enemy_attack(cub3d, sprite));
	if (sprite->hit)
		sprite->anim_frame += cub3d->d_time;
	if (sprite->anim_frame == 0)
		return (0);
	if (sprite->anim_frame < ENEMY_DIE_SPEED * 0.2)
		return (1);
	if (sprite->anim_frame < ENEMY_DIE_SPEED * 0.4)
		return (2);
	if (sprite->anim_frame < ENEMY_DIE_SPEED * 0.6)
		return (3);
	if (sprite->anim_frame < ENEMY_DIE_SPEED * 0.8)
		return (4);
	if (sprite->anim_frame < ENEMY_DIE_SPEED)
		return (5);
	else
		return (handle_enemy_die_anim_end(cub3d, sprite));
}
