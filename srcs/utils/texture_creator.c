/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_creator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:33:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/26 16:26:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*get_texture_path(char *info)
{
	int		i;
	int		size_to_copy;
	char	*path;
	i = 2;
	while (ft_isspace(info[i]))
		i++;
	size_to_copy = ft_strlen(info) - i + 1;
	path = (char *)malloc(sizeof(char) * size_to_copy);
	if (!path)
		return (NULL);
	ft_strlcpy(path, &info[i], size_to_copy);
	return (path);
}

void	texture_creator(t_textures *texture, char *info)
{
	texture->identifier = ft_substr(info, 0, 2);
	texture->path = get_texture_path(info);
}