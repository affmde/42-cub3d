/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:05:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/20 09:25:12 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_player(char **map, t_camera *camera)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_start_pos(map[i][j]))
			{
				camera->x = j;
				camera->y = i;
			}
		}
	}
}

static void	check_directions(t_cub3d *cub3d, t_camera *cam)
{
	if (cub3d->map->map[(int)cam->y][(int)cam->x] == 'N')
	{
		cam->dir_y = -1;
		cam->plane_x = cam->d_fov;
	}
	else if (cub3d->map->map[(int)cam->y][(int)cam->x] == 'S')
	{
		cam->dir_y = 1;
		cam->plane_x = -cam->d_fov;
	}
	else if (cub3d->map->map[(int)cam->y][(int)cam->x] == 'E')
	{
		cam->dir_x = 1;
		cam->plane_y = cam->d_fov;
	}
	else if (cub3d->map->map[(int)cam->y][(int)cam->x] == 'W')
	{
		cam->dir_x = -1;
		cam->plane_y = -cam->d_fov;
	}
}

void	camera_init(t_cub3d *cub3d)
{
	t_camera	*cam;

	cam = &cub3d->camera;
	cam->half_height = HEIGHT / 2;
	find_player(cub3d->map->map, cam);
	cam->d_fov = 0.66;
	cam->dir_x = 0;
	cam->dir_y = 0;
	cam->plane_x = 0;
	cam->plane_y = 0;
	cam->x += 0.5;
	cam->y += 0.5;
	check_directions(cub3d, cam);
}
