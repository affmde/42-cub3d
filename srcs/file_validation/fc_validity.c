/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_validity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:11:31 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/05 11:33:31 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_values(t_color *color)
{
	if (color->r < 0 || color->r > 255)
		return (1);
	if (color->g < 0 || color->g > 255)
		return (1);
	if (color->b < 0 || color->b > 255)
		return (1);
	return (0);
}

int	check_walls_color(t_cub3d *cub3d)
{
	t_list	*tmp;
	t_walls	*element;

	tmp = cub3d->walls;
	while (tmp)
	{
		element = tmp->content;
		if (!element->color)
			return (1);
		if (check_values(element->color))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_repeated_walls(t_cub3d *cub3d, t_elements_check *element)
{
	t_list		*aux;
	t_walls		*wall;
	
	aux = cub3d->textures;
	while (aux)
	{
		wall = aux->content;
		if (!ft_strncmp(wall->identifier, "F", ft_strlen(wall->identifier)))
			element->f++;
		else if (!ft_strncmp(wall->identifier, "C", ft_strlen(wall->identifier)))
			element->c++;
		aux = aux->next;
	}
}