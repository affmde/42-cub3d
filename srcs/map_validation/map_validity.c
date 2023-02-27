/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:17:36 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 13:36:54 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_characters(t_map *map, t_map_check *map_check)
{
	t_list	*tmp;
	char	*str;
	int		i;

	tmp = map->map;
	while (tmp)
	{
		i = 0;
		str = tmp->content;
		while (str[i])
		{
			if (!is_valid_char(str[i]))
				map_check->other_chars++;
			if (is_start_pos(str[i]))
				map_check->start_position++;
			i++;
		}
		if (!ft_strncmp(str, "\n", ft_strlen(str)))
			map_check->empty_lines++;
		tmp = tmp->next;
	}
}

int	valid_map(t_cub3d *cub3d)
{
	t_map_check map_check;

	map_check.start_position = 0;
	map_check.other_chars = 0;
	map_check.empty_lines = 0;
	check_characters(cub3d->map, &map_check);
	if (map_check.other_chars)
		return (1);
	if (map_check.start_position != 1)
		return (1);
	if (map_check.empty_lines)
		return (1);
	return (0);
}
