/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 17:28:35 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	raycasting(t_cub3d *cub3d)
{
	float	ray_angle;
	int		i;
	
	ray_angle = cub3d->camera->player_angle - cub3d->camera->half_fov;
	i = 0;
	while (i < WIDTH)
	{
		
		ray_angle += cub3d->camera->angle_increment;
		i++;
	}
	return (0);
}