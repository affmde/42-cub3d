/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:15:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 17:14:51 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*cub3d_init(void)
{
	t_cub3d	*cub3d;

	cub3d = ft_calloc(1, sizeof(t_cub3d));
	if (!cub3d)
		return (NULL);
	return (cub3d);
}

static void	movement_init(t_movement *m)
{
	m->move_backwards = 0;
	m->move_forward = 0;
	m->move_right = 0;
	m->move_left = 0;
	m->turn_left = 0;
	m->turn_right = 0;
}

void	cub_config_init(t_cub3d *cub3d)
{
	camera_init(cub3d);
	ray_init(cub3d);
	movement_init(&cub3d->movement);
}
