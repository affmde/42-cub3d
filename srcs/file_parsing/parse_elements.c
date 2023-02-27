/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:32:16 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 09:31:22 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*trim_line(char *line)
{
	char	*new;

	new = ft_strtrim(line, " \t");
	if (!new)
		return (NULL);
	free(line);
	return (new);
}

static t_textures	*create_texture(char *line)
{
	t_textures	*texture;

	texture = ft_calloc(1, sizeof(t_textures));
	if (!texture)
		return (NULL);
	texture_creator(texture, line);
	ft_printf("id: %s path: %s\n", texture->identifier, texture->path);
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
	ft_printf("identifier: %d\n", identifier);
	if(identifier == 0)
		return (1);
	else if (identifier == 1)
		ft_lstadd_back(&cub3d->textures, ft_lstnew(create_texture(line)));
	else if (identifier == 2)
		ft_lstadd_back(&cub3d->walls, ft_lstnew(create_wall(line)));
	return (0);
}

int	parse_elements(int fd, t_cub3d *cub3d)
{
	char	*line;
	
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		line = trim_line(line);
		if (!line)
			return (1);
		if (parse_line(line, cub3d))
		{
			free(line);
			break;
		}
		free(line);
	}
	close(fd);
	return (0);
}