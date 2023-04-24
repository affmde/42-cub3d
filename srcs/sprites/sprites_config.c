/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:47:14 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/24 13:25:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*allocate_sprite(void)
{
	t_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		error_msg_exit("couldn't allocate sprite");
	return (sprite);
}

static void	get_sprites(t_cub3d *cub3d)
{
	int			i;
	int			j;
	t_sprite	*sprite;

	i = -1;
	while (++i < cub3d->map->height)
	{
		j = -1;
		while (++j < (int)ft_strlen(cub3d->map->map[i]))
		{
			if (cub3d->map->map[i][j] == '2')
			{
				sprite = allocate_sprite();
				sprite->order = cub3d->sp_manager.total_sprites;
				sprite->x = j + 0.5;
				sprite->y = i + 0.5;
				sprite->alive = 1;
				sprite->anim_frame = 0;
				sprite->hit = 0;
				sprite->identifier = cub3d->map->map[i][j];
				ft_lstadd_back(&cub3d->sp_manager.sprites_list,
					ft_lstnew(sprite));
				cub3d->sp_manager.total_sprites++;
			}
		}
	}
}

void	sprites_config(t_cub3d *cub3d)
{
	get_sprites(cub3d);
	load_sprite_texture(cub3d);
}
