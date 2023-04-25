/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent_attack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:01:03 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 17:07:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	opponent_attack(t_cub3d *cub3d)
{
	int			random;
	t_sprite	*sprite;

	sprite = find_sprite(cub3d, cub3d->ray.map_x, cub3d->ray.map_y);
	if (sprite && sprite->alive && !sprite->is_attacking)
	{
		srand(time(NULL));
		random = rand() % 100;
		if (random < 80)
			sprite->is_attacking = 1;
	}
}
