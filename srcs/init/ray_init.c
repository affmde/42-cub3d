/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:13:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/18 15:23:26 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_reset_values(t_ray *ray)
{
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->direction = 0;
	ray->perp_wall_dist = 0;
	ray->r_start = 0;
	ray->r_end = 0;
	ray->wall_hit_x = 0;
	ray->index = 0;
}

void	ray_init(t_cub3d *cub3d)
{
	t_ray	*ray;

	ray = &cub3d->ray;
	ray->ceiling_color = create_rgb(get_wall_color("C", cub3d));
	ray->floor_color = create_rgb(get_wall_color("F", cub3d));
	ray_reset_values(ray);
}
