/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:30:38 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/17 11:38:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*line_add_border(char *line, t_cub3d *cub3d)
{
	char	*str;
	int		i;
	int		total_chars;

	total_chars = cub3d->map->max_length + 3;
	str = ft_calloc(total_chars, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	str[i++] = '@';
	ft_memcpy(&str[i], line, ft_strlen(line));
	i += ft_strlen(line);
	while (i < total_chars - 1)
		str[i++] = '@';
	str[i] = '\0';
	return (str);
}

static int	populate_map(t_cub3d *cub3d, char **arr)
{
	int	i;

	i = 0;
	while (i < cub3d->map->height)
	{
		arr[i + 1] = line_add_border(cub3d->map->map[i], cub3d);
		if (!arr[i + 1])
			return (-1);
		i++;
	}
	return (i);
}

char	**get_map_copy(t_cub3d *cub3d)
{
	char	**arr;
	int		i;

	arr = ft_calloc(cub3d->map->height + 3, sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = ft_calloc(cub3d->map->max_length + 3, sizeof(char));
	if (!arr[0])
		return (NULL);
	ft_memset(arr[0], '@', cub3d->map->max_length + 2);
	arr[0][cub3d->map->max_length + 2] = '\0';
	i = populate_map(cub3d, arr);
	if (i < 0)
		return (NULL);
	arr[i + 1] = ft_calloc(cub3d->map->max_length + 3, sizeof(char));
	if (!arr[0])
		return (NULL);
	ft_memset(arr[i + 1], '@', cub3d->map->max_length + 2);
	arr[i + 1][cub3d->map->max_length + 2] = '\0';
	i++;
	arr[i + 1] = NULL;
	return (arr);
}
