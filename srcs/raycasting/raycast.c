/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/06 19:48:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	raycasting(t_cub3d *cub3d, float angle)
{
	float	ray_angle;
	float	ray_cos;
	float	ray_sin;
	char	c;
	
	ray_angle = angle;
	float x = cub3d->camera->x / scale;
	float y = cub3d->camera->y / scale;
	ray_cos = cosf(degrees_to_radians(ray_angle)) / scale;
	ray_sin = sinf(degrees_to_radians(ray_angle)) / scale;
	c = '0';
	while (c != '1')
	{
		x += ray_cos;
		y += ray_sin;
		c = cub3d->map->map[(int)floor(y)][(int)floor(x)];
	}
	float distance = sqrt(pow(cub3d->camera->x / scale - x, 2) + pow(cub3d->camera->y / scale - y, 2));
	return (distance);
}