/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_interact_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:58:24 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/26 16:58:27 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	check_door_char(t_cub3d *cub3d)
{
	if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'C')
		return (1);
	if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'O')
		return (1);
	return (0);
}

void	handle_door_open(t_cub3d *cub3d)
{
	t_sprite	*sprite;

	sprite = find_sprite(cub3d, cub3d->ray.map_x, cub3d->ray.map_y);
	if (fabs(sprite->x - cub3d->camera.x) > 1.5
		|| fabs(sprite->y - cub3d->camera.y) > 1.5)
		return ;
	if (sprite)
	{
		sprite->hit = 1;
		if (sprite->open)
			sprite->open = 0;
		else
			sprite->open = 1;
		sprite->anim_frame = 0;
		if (cub3d->map->map[(int)(sprite->y)][(int)sprite->x] == 'C')
			cub3d->map->map[(int)(sprite->y)][(int)sprite->x] = 'O';
		else if (cub3d->map->map[(int)(sprite->y)][(int)sprite->x] == 'O')
			cub3d->map->map[(int)(sprite->y)][(int)sprite->x] = 'C';
	}
}
