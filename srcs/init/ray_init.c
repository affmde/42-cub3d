/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:13:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/20 09:26:49 by andrferr         ###   ########.fr       */
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
	ray->index = 0;
}

void	ray_init(t_cub3d *cub3d)
{
	t_ray	*ray;

	ray = &cub3d->ray;
	ray->ceiling_color = create_rgb(get_wall_color("C", cub3d));
	ray->floor_color = create_rgb(get_wall_color("F", cub3d));
	ray->dir_x = malloc(sizeof(double) * WIDTH);
	if (!ray->dir_x)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Couldn't create buffer for ray directions", 2);
		exit (1);
	}
	ray->dir_y = malloc(sizeof(double) * WIDTH);
	if (!ray->dir_y)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Couldn't create buffer for ray directions", 2);
		exit (1);
	}
	ray_reset_values(ray);
}
