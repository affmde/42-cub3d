/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:47:14 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/21 09:56:04 by andrferr         ###   ########.fr       */
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
				sprite->identifier = cub3d->map->map[i][j];
				ft_lstadd_back(&cub3d->sp_manager.sprites_list, ft_lstnew(sprite));
				cub3d->sp_manager.total_sprites++;
			}
		}
	}
}

void	swap_data(t_list *a, t_list *b)
{
	t_sprite tmp;

	ft_memcpy(&tmp, a->content, sizeof(tmp));
	ft_memcpy(a->content, b->content, sizeof(a->content));
	ft_memcpy(b->content, &tmp, sizeof(b->content));
}

void	sort_sprites(t_list *sprites)
{
	t_list	*tmp;
	t_list	*index;
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
			printf("s1: %f s2: %f\n", s1->distance, s2->distance);
			if (s1->distance > s2->distance)
				swap_data(tmp, index);
			index = index->next;
		}
		tmp = tmp->next;
	}
}

void	sprites_config(t_cub3d *cub3d)
{
	get_sprites(cub3d);
	sort_sprites(cub3d->sp_manager.sprites_list);
	load_sprite_texture(cub3d);
}
