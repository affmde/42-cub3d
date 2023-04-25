/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:56:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 09:51:01 by andrferr         ###   ########.fr       */
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

int	get_sprite_text(t_cub3d *cub3d, t_sprite *sprite)
{
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
	else
	{
		sprite->alive = 0;
		return (4);
	}
}
