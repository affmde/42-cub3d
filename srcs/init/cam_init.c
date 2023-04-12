/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:05:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/06 21:09:48 by andrferr         ###   ########.fr       */
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

static float	get_player_angle(char **map, t_camera *camera)
{
	int	x;
	int	y;

	x = (int)camera->x;
	y = (int)camera->y;
	if (map[y][x] == 'N')
		return (90);
	if (map[y][x] == 'S')
		return (270);
	if (map[y][x] == 'E')
		return (0);
	if (map[y][x] == 'W')
		return (180);
	return (-1);
}

t_camera	*camera_init(t_cub3d *cub3d)
{
	t_camera *cam;

	cam = ft_calloc(1, sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->fov = 60;
	cam->half_fov = cam->fov / 2;
	cam->half_height = HEIGHT / 2;
	cam->half_width = WIDTH / 2;
	cam->precision = 64;
	find_player(cub3d->map->map, cam);
	cam->player_angle = get_player_angle(cub3d->map->map, cam);
	cam->angle_increment = (float)cam->fov / WIDTH;
	cam->distance_to_plane = cam->half_width / tan(degrees_to_radians(30));
	cam->x = cam->x * scale + (scale / 2);
	cam->y = cam->y * scale + (scale / 2);
	return (cam);
}
