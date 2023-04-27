/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda_algo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:01:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/27 08:53:08 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	x_smaller_y(t_cub3d *cub3d, int x)
{
	cub3d->ray.side_dist_x += cub3d->ray.delta_dist_x;
	cub3d->ray.map_x += cub3d->ray.step_x;
	if (cub3d->ray.dir_x[x] > 0)
		cub3d->ray.direction = EAST;
	else
		cub3d->ray.direction = WEST;
}

static void	y_smaller_x(t_cub3d *cub3d, int x)
{
	cub3d->ray.side_dist_y += cub3d->ray.delta_dist_y;
	cub3d->ray.map_y += cub3d->ray.step_y;
	if (cub3d->ray.dir_y[x] > 0)
		cub3d->ray.direction = SOUTH;
	else
		cub3d->ray.direction = NORTH;
}

void	dda_algo(t_cub3d *cub3d, int x, int shoot)
{
	int	wall_between;

	wall_between = 0;
	while (cub3d->ray.hit == 0)
	{
		if (cub3d->ray.side_dist_x < cub3d->ray.side_dist_y)
			x_smaller_y(cub3d, x);
		else
			y_smaller_x(cub3d, x);
		if  (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'C')
			wall_between = 1;
		if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == '2' && !wall_between)
			opponent_attack(cub3d);
		if (shoot)
		{
			if(shoot == 1 && cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == 'C')
				return ;
			if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == '2'\
			&& shoot == 1)
			{
				handle_shoot_hit(cub3d);
				return ;
			}
			if (check_door_char(cub3d) && shoot == 2)
				return (handle_door_open(cub3d));
		}
		if (cub3d->map->map[cub3d->ray.map_y][cub3d->ray.map_x] == '1')
			cub3d->ray.hit = 1;
	}
}
