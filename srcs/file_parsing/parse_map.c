/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:57:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/01 14:17:15 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_map	*map_creator(t_cub3d *cub3d)
{
	t_map	*map;
	t_list	*aux;
	t_list	*map_list;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	aux = cub3d->file_data;
	while (check_identifier(aux->content) != 4)
		aux = aux->next;
	map_list = NULL;
	while (aux)
	{
		ft_lstadd_back(&map_list, ft_lstnew(ft_strdup(aux->content)));
		aux = aux->next;
	}
	aux = map_list;
	map->height = ft_lstsize(aux);
	map->map = list_to_matrix(map_list);
	ft_lstclear(&map_list, free);
	return (map);
}

int	parse_map(t_cub3d *cub3d)
{
	cub3d->map = map_creator(cub3d);
	if (!cub3d->map)
		return (1);
	return (0);
}
