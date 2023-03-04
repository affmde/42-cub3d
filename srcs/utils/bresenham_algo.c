/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:36:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 15:09:44 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_pos	populate_position(int x, int y, int z, int color)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	pos.color = color;
	return (pos);
}

static void	line_params(t_pos pos_0, t_pos pos_1, t_params *params)
{
	if (pos_0.x < pos_1.x)
		params->sx = 1;
	else
		params->sx = -1;
	if (pos_0.y < pos_1.y)
		params->sy = 1;
	else
		params->sy = -1;
	params->dx = ft_abs(pos_1.x - pos_0.x);
	params->dy = ft_abs(pos_1.y - pos_0.y);
	params->offset = params->dx - params->dy;
	params->error = 0;
}

void	bresenham_algo(t_pos pos_0, t_pos pos_1, t_img *image)
{
	t_params	params;

	line_params(pos_0, pos_1, &params);
	while (pos_0.y != pos_1.y || pos_0.x != pos_1.x)
	{
		put_pixel(image, pos_0.x, pos_0.y, pos_0.color);
		params.error = params.offset * 2;
		if (params.error > -params.dy)
		{
			params.offset -= params.dy;
			pos_0.x += params.sx;
		}
		if (params.error < params.dx)
		{
			params.offset += params.dx;
			pos_0.y += params.sy;
		}
	}
}