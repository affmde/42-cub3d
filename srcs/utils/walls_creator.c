/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:13:48 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/28 09:46:33 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



static t_color *color_creator(char *info)
{
	t_color	*color;
	char	**arr;

	while (!ft_isdigit(*info))
		info++;
	arr = ft_split(info, ',');
	if (!arr)
		return(NULL);
	color = ft_calloc(1, sizeof(t_color));
	if (!color)
		return (NULL);
	color->r = ft_atoi(arr[0]);
	color->g = ft_atoi(arr[1]);
	color->b = ft_atoi(arr[2]);
	clean_char_arr(arr);
	return (color);
}

void	walls_creator(t_walls *wall, char *info)
{
	wall->identifier = ft_substr(info, 0, 1);
	wall->color = color_creator(info);
}