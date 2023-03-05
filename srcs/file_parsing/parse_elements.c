/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:32:16 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/05 10:26:22 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static t_textures	*create_texture(char *line)
{
	t_textures	*texture;

	texture = ft_calloc(1, sizeof(t_textures));
	if (!texture)
		return (NULL);
	texture_creator(texture, line);
	return (texture);
}

static t_walls *create_wall(char *line)
{
	t_walls	*wall;

	wall = ft_calloc(1, sizeof(t_walls));
	if (!wall)
		return (NULL);
	walls_creator(wall, line);
	return (wall);
}

int	parse_line(char *line, t_cub3d *cub3d)
{
	int	identifier;

	identifier = check_identifier(line);
	if(identifier == 0)
		return (1);
	else if (identifier == 1)
		ft_lstadd_back(&cub3d->textures, ft_lstnew(create_texture(line)));
	else if (identifier == 2)
		ft_lstadd_back(&cub3d->walls, ft_lstnew(create_wall(line)));
	return (0);
}

int	parse_elements(t_cub3d *cub3d)
{
	t_list	*aux;

	aux = cub3d->file_data;
	while (check_identifier(aux->content) != 4 && aux)
	{
		aux->content = trim_line(aux->content, " \t");
		if (!aux->content)
			return (1);
		if (parse_line(aux->content, cub3d))
			return (1);
		aux = aux->next;
	}
	return (0);
}
