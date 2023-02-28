/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:07:22 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/28 11:08:22 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	print_map_elements(t_cub3d *cub3d)
{
	t_list *aa = cub3d->textures;
	while (aa)
	{
		t_textures *aux;

		aux = (t_textures *)aa->content;
		ft_printf("ident: %s - path: %s\n", aux->identifier, aux->path);
		aa = aa->next;
	}
	t_list *a = cub3d->map->map;
	int	i;
	i = 0;
	while (a)
	{
		ft_printf("i: %d - %s\n",i, a->content);
		a = a->next;
		i++;
	}
	ft_printf("map height: %d\n", cub3d->map->height);
}
