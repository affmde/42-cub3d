/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:05:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 17:29:14 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static int	get_player_angle(char **map, t_camera *camera)
{
	if (map[camera->y][camera->x] == 'N')
		return (90);
	if (map[camera->y][camera->x] == 'S')
		return (270);
	if (map[camera->y][camera->x] == 'E')
		return (0);
	if (map[camera->y][camera->x] == 'N')
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
	cam->half_fov = cam->half_fov / 2;
	cam->half_height = HEIGHT / 2;
	cam->half_width = WIDTH / 2;
	cam->precision = 64;
	find_player(cub3d->map->map, cam);
	cam->player_angle = get_player_angle(cub3d->map->map, cam);
	cam->angle_increment = cam->fov / WIDTH;
	return (cam);
}