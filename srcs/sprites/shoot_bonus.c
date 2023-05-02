/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:06:07 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 16:06:17 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	allow_shoot(t_weapon *w)
{
	if (w->anim_frame > 0)
		return (0);
	if (w->bullets <= 0 || w->bullets > w->max_bullets)
		return (0);
	return (1);
}

void	handle_shoot_hit(t_cub3d *cub3d)
{
	t_sprite	*sprite;

	sprite = find_sprite(cub3d, cub3d->ray.map_x, cub3d->ray.map_y);
	if (hypot((sprite->x - cub3d->camera.x), (sprite->y - cub3d->camera.y)) > 7)
		return ;
	if (sprite)
	{
		sprite->hit = 1;
		cub3d->map->map[(int)(sprite->y)][(int)sprite->x] = '0';
	}
}

t_sprite	*find_sprite(t_cub3d *cub3d, int x, int y)
{
	t_list		*tmp;
	t_sprite	*sprite;

	tmp = cub3d->sp_manager.sprites_list;
	while (tmp)
	{
		sprite = tmp->content;
		if ((int)sprite->x == x && (int)sprite->y == y)
			return (sprite);
		tmp = tmp->next;
	}
	return (NULL);
}

void	shoot(t_cub3d *cub3d)
{
	if (allow_shoot(&cub3d->weapon))
	{
		cub3d->weapon.bullets--;
		if (cub3d->weapon.bullets < 0)
			cub3d->weapon.bullets = 0;
		cub3d->weapon.state = 1;
		raycasting(cub3d, (int)(WIDTH / 2), 1);
	}
}
