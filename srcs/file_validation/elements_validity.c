/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:23:54 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/03 12:39:52 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_repeated_textures(t_cub3d *cub3d, t_elements_check *element)
{
	t_list		*aux;
	t_textures	*texture;

	aux = cub3d->textures;
	while (aux)
	{
		texture = aux->content;
		if (!ft_strncmp(texture->identifier,
				"NO", ft_strlen(texture->identifier)))
			element->n++;
		else if (!ft_strncmp(texture->identifier,
				"SO", ft_strlen(texture->identifier)))
			element->s++;
		else if (!ft_strncmp(texture->identifier,
				"EA", ft_strlen(texture->identifier)))
			element->e++;
		else if (!ft_strncmp(texture->identifier,
				"WE", ft_strlen(texture->identifier)))
			element->w++;
		aux = aux->next;
	}
}

static int	pass_elements_check(t_elements_check *element)
{
	if (element->n != 1)
		return (1);
	if (element->s != 1)
		return (1);
	if (element->e != 1)
		return (1);
	if (element->w != 1)
		return (1);
	if (element->f != 1)
		return (1);
	if (element->c != 1)
		return (1);
	return (0);
}

int	elements_validity(t_cub3d *cub3d)
{
	t_elements_check	element;

	element.n = 0;
	element.s = 0;
	element.e = 0;
	element.w = 0;
	element.f = 0;
	element.c = 0;
	check_repeated_textures(cub3d, &element);
	check_repeated_walls(cub3d, &element);
	if (pass_elements_check(&element))
		return (1);
	if (check_walls_color(cub3d))
		return (2);
	return (0);
}
