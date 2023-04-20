/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:18:03 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/20 17:58:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	project_sprites(t_cub3d *cub3d)
{
	double		sprite_x;
	double		sprite_y;
	t_list		*tmp;
	t_sprite	*sprite;
	double		inv_det;
	double		transform_x;
	double		transform_y;

	tmp = cub3d->sprites_list;
	while (tmp)
	{
		sprite = tmp->content;
		sprite_x = sprite->x - cub3d->camera.x;
		sprite_y = sprite->y  - cub3d->camera.y;
		printf("sprite_x: %f sprite_y: %f\n", sprite_x, sprite_y);
		inv_det = 1.0 / (cub3d->camera.plane_x * cub3d->camera.dir_y - cub3d->camera.dir_x * cub3d->camera.plane_y);
		transform_x = inv_det * (cub3d->camera.dir_y * sprite_x - cub3d->camera.dir_x * sprite_y);
		transform_y = inv_det * (-cub3d->camera.plane_y * sprite_x + cub3d->camera.plane_x * sprite_y);
		tmp = tmp->next;
	}

}
