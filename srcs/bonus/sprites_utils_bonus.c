/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:31:24 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 16:32:14 by andrferr         ###   ########.fr       */
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

static int	handle_end_enemy_attack(t_cub3d *cub3d, t_sprite *sprite)
{
	int	hit;

	sprite->is_attacking = 0;
	hit = rand() % 100;
	if (hit < HIT_PERCENTAGE && hypot((sprite->x - cub3d->camera.x), \
		(sprite->y - cub3d->camera.y)) < 20)
	{
		cub3d->health -= DAMAGE;
		cub3d->blood.is_rendering = 1;
	}
	sprite->anim_frame = 0;
	return (0);
}

int	enemy_attack(t_cub3d *cub3d, t_sprite *sprite)
{
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
			return (handle_end_enemy_attack(cub3d, sprite));
	}
	return (0);
}
