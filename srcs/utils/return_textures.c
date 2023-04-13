/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:13:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/13 17:21:39 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture(char *identifier, t_cub3d *cub3d)
{
	t_list		*tmp;
	t_textures	*texture;

	if (!cub3d || !identifier || ft_strlen(identifier) != 2)
		return (NULL);
	tmp = cub3d->textures;
	while (tmp)
	{
		texture = tmp->content;
		if (!ft_strncmp(texture->identifier, identifier, 2))
			return (texture->path);
		tmp = tmp->next;
	}
	return (NULL);
}

t_color	*get_wall_color(char *identifier, t_cub3d *cub3d)
{
	t_list		*tmp;
	t_walls		*element;
	
	if (!cub3d || !identifier || ft_strlen(identifier) != 1)
		return (NULL);
	tmp = cub3d->walls;
	while (tmp)
	{
		element = tmp->content;
		if (!ft_strncmp(element->identifier, identifier, 1))
			return (element->color);
		tmp = tmp->next;
	}
	return (NULL);
}

t_textures	*return_texture(char *identifier, t_cub3d *cub3d)
{
	t_list		*tmp;
	t_textures	*element;
	
	if (!cub3d || !identifier)
		return (NULL);
	tmp = cub3d->textures;
	while (tmp)
	{
		element = tmp->content;
		if (!ft_strncmp(element->identifier, identifier, ft_strlen(identifier)))
			return (element);
		tmp = tmp->next;
	}
	return (NULL);
}