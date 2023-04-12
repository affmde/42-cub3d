/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:07:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 15:39:07 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(t_color *color)
{
	int	r;
	int	g;
	int	b;

	if (!color)
		return (-1);
	r = color->r;
	g = color->g;
	b = color->b;
	return (0xFFFFFF & (r << 16 | g << 8 | b));
}