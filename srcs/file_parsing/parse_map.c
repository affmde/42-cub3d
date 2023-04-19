/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:57:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/18 16:34:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	*map_creator(t_cub3d *cub3d)
{
	t_map	*map;
	t_list	*aux;
	t_list	*map_list;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	aux = cub3d->file_data;
	while (check_identifier(aux->content) != 4 && check_identifier(aux->content))
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

static void	get_longer_line(t_cub3d *cub3d)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while(cub3d->map->map[i])
	{
		if ((int)ft_strlen(cub3d->map->map[i]) > len)
			len = ft_strlen(cub3d->map->map[i]);
		i++;
	}
	cub3d->map->max_length = len;
}

int	parse_map(t_cub3d *cub3d)
{
	cub3d->map = map_creator(cub3d);
	if (!cub3d->map)
		return (1);
	get_longer_line(cub3d);
	return (0);
}
