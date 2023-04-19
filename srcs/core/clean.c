/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:36:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/18 15:45:46 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

void	delete_texture_node(void *node)
{
	t_textures	*texture;

	texture = (t_textures *)node;
	if (!texture)
		return ;
	ft_strdel(&texture->identifier);
	ft_strdel(&texture->path);
	if (texture->img)
		free(texture->img);
	free(texture);
}

void	delete_wall_node(void *node)
{
	t_walls	*wall;

	wall = (t_walls *)node;
	if (!wall)
		return ;
	ft_strdel(&wall->identifier);
	free(wall->color);
	free(wall);
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d)
	{
		if (cub3d->file_data)
			ft_lstclear(&cub3d->file_data, free);
		if (cub3d->textures)
			ft_lstclear(&cub3d->textures, delete_texture_node);
		if (cub3d->walls)
			ft_lstclear(&cub3d->walls, delete_wall_node);
		if (cub3d->map)
		{
			if (cub3d->map->map)
				clean_char_arr(cub3d->map->map);
			free(cub3d->map);
		}
		free(cub3d);
	}
}
