/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:56:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 16:28:56 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	swap_data(t_sprite *a, t_sprite *b)
{
	t_sprite	tmp;

	tmp = *a;
	ft_memcpy(a, b, sizeof(*a));
	ft_memcpy(b, &tmp, sizeof(*b));
}

void	sort_sprites(t_list *sprites)
{
	t_list		*tmp;
	t_list		*index;
	t_sprite	*s1;
	t_sprite	*s2;

	if (!sprites)
		return ;
	tmp = sprites;
	while (tmp)
	{
		index = tmp->next;
		while (index)
		{
			s1 = tmp->content;
			s2 = index->content;
			if (s1->distance < s2->distance)
				swap_data(s1, s2);
			index = index->next;
		}
		tmp = tmp->next;
	}
}

int	enemy_attack(t_cub3d *cub3d, t_sprite *sprite)
{
	int	hit;

	if (sprite->is_attacking)
	{
		sprite->anim_frame += cub3d->d_time;
		if (sprite->anim_frame < ENEMY_SHOOT * 0.20)
			return (6);
		if (sprite->anim_frame < ENEMY_SHOOT * 0.40)
			return (7);
		if (sprite->anim_frame < ENEMY_SHOOT * 0.60)
			return (8);
		else if (sprite->anim_frame < ENEMY_SHOOT)
			return (9);
		else
		{
			sprite->is_attacking = 0;
			hit = rand() % 100;
			if (hit < HIT_PERCENTAGE)
				cub3d->health -= DAMAGE;
			sprite->anim_frame = 0;
			return (0);
		}
	}
	return (0);
}

int	get_sprite_text(t_cub3d *cub3d, t_sprite *sprite)
{
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
	{
		sprite->alive = 0;
		cub3d->sp_manager.enemies_left--;
		if (cub3d->sp_manager.enemies_left <= 0)
			cub3d->won = 1;
		return (5);
	}
}
