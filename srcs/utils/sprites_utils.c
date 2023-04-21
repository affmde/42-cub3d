/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:56:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/21 14:39:01 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
