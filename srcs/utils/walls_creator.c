/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:13:48 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 12:51:17 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_arr_values(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	if (i != 3)
	{
		clean_char_arr(arr);
		return (1);
	}
	return (0);
}

static int	attribute_colors(t_color *color, char **arr)
{
	if (contains_non_digit(arr[0]))
		return (1);
	if (contains_non_digit(arr[1]))
		return (1);
	if (contains_non_digit(arr[2]))
		return (1);
	color->r = ft_atoi(arr[0]);
	color->g = ft_atoi(arr[1]);
	color->b = ft_atoi(arr[2]);
	color->full_color = (color->r * 1000 + color->g) * 1000 + color->b;
	return (0);
}

static t_color	*color_creator(char *info)
{
	t_color	*color;
	char	**arr;

	while (!ft_isdigit(*info))
		info++;
	arr = ft_split(info, ',');
	if (!arr)
		return (NULL);
	color = ft_calloc(1, sizeof(t_color));
	if (!color)
		return (NULL);
	if (count_arr_values(arr))
	{
		free(color);
		return (NULL);
	}
	if (attribute_colors(color, arr))
		return (NULL);
	clean_char_arr(arr);
	return (color);
}

void	walls_creator(t_walls *wall, char *info)
{
	wall->identifier = ft_substr(info, 0, 1);
	wall->color = color_creator(info);
}
