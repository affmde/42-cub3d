/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_config_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:06:34 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 16:06:44 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static t_sprite	*allocate_sprite(void)
{
	t_sprite	*sprite;

	sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		error_msg_exit("couldn't allocate sprite");
	return (sprite);
}

static void	sprite_info(t_cub3d *cub3d, t_sprite *sprite, int i, int j)
{
	sprite->order = cub3d->sp_manager.total_sprites;
	sprite->x = j + 0.5;
	sprite->y = i + 0.5;
	sprite->alive = 1;
	sprite->anim_frame = 0;
	sprite->hit = 0;
	sprite->is_attacking = 0;
	sprite->identifier = cub3d->map->map[i][j];
	sprite->open = 0;
	if (sprite->identifier == 'O')
		sprite->open = 1;
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
			if (cub3d->map->map[i][j] == '2' || cub3d->map->map[i][j] == 'O'
			|| cub3d->map->map[i][j] == 'C')
			{
				sprite = allocate_sprite();
				sprite_info(cub3d, sprite, i, j);
				ft_lstadd_back(&cub3d->sp_manager.sprites_list,
					ft_lstnew(sprite));
				if (cub3d->map->map[i][j] == '2')
					cub3d->sp_manager.enemies_left++;
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
