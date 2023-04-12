/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:10:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/12 09:19:33 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*float	raycasting(t_cub3d *cub3d, float angle)
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
}*/

float	ray_check_horizontal(t_cub3d *cub3d, float angle)
{
	t_pos	start;
	t_pos	next;
	int		grid_x;
	int		grid_y;
	int		Ya;
	int		Xa;
	
	start.x = cub3d->camera->x;
	start.y = cub3d->camera->y;
	if (degrees_to_radians(angle) > degrees_to_radians(0) && degrees_to_radians(angle) < degrees_to_radians(180)) //Ray up direction
	{
		next.y = (int)(floor(start.y  /scale)) * scale - 1;
		Ya = -scale;
	}
	else
	{
		next.y = (int)(floor(start.y / scale)) * scale + scale;
		Ya = scale;
	}
	next.x = start.x + (start.y - next.y) / tan(degrees_to_radians(angle));
	Xa = (int)(scale / tan(degrees_to_radians(angle)));
	while (1)
	{
		grid_x = next.x / scale;
		grid_y = next.y / scale;
		if (grid_y < 0 || grid_y >= cub3d->map->height)
			break;
		if(grid_x < 0 || grid_x >= (int)ft_strlen(cub3d->map->map[grid_y]))
			break ;
		if (cub3d->map->map[grid_y][grid_x] == '1')
			break;
		next.x += Xa;
		next.y += Ya;
	}
	float distance;
	distance = sqrt(pow(start.x - next.x, 2) + pow(start.y - next.y, 2));
	if (angle == cub3d->camera->player_angle)
	{
		printf("Player Pos y: %d x: %d. On grid y: %d x: %d\n", start.y, start.x, start.y/scale, start.x / scale);
		printf("Wall Pos y: %d x: %d. On grid y: %d x: %d\n", next.y, next.x, grid_y, grid_x);
		printf("Distance: %f Angle: %f\n", distance, angle);
	}
		
	return (distance);
}

float	ray_check_vertically(t_cub3d *cub3d, float angle)
{
	t_pos	start;
	t_pos	next;
	int		grid_x;
	int		grid_y;
	int		Ya;
	int		Xa;
	
	start.x = cub3d->camera->x;
	start.y = cub3d->camera->y;
	if (degrees_to_radians(angle) > degrees_to_radians(270) || degrees_to_radians(angle) < degrees_to_radians(90)) //Ray right direction
	{
		next.x = (int)(floor(start.x / scale)) * scale + scale;
		Xa = scale;
	}
	else
	{
		next.x = (int)(floor(start.x / scale)) * scale - 1;
		Xa = -scale;
	}
	next.y = start.y + (start.x - next.x) * tan(degrees_to_radians(angle));
	Ya = (int)(scale * tan(degrees_to_radians(angle)));
	while (1)
	{
		grid_x = next.x / scale;
		grid_y = next.y / scale;
		if (grid_y < 0 || grid_y >= cub3d->map->height)
			break;
		if(grid_x < 0 || grid_x >= (int)ft_strlen(cub3d->map->map[grid_y]))
			break ;
		if (cub3d->map->map[grid_y][grid_x] == '1')
			break;
		next.x += Xa;
		next.y += Ya;
	}
	float distance;
	distance = sqrt(pow(start.x - next.x, 2) + pow(start.y - next.y, 2));
	if (angle == cub3d->camera->player_angle)
	{
		printf("vertical check: \n");
		printf("Player Pos y: %d x: %d. On grid y: %d x: %d\n", start.y, start.x, start.y/scale, start.x / scale);
		printf("Wall Pos y: %d x: %d. On grid y: %d x: %d\n", next.y, next.x, grid_y, grid_x);
		printf("Distance: %f Angle: %f\n", distance, angle);
	}
	return (distance);
}

float	raycasting(t_cub3d *cub3d, float angle)
{
	float	distance;
	float	horizontal_distance;
	float	vertical_distance;
	
	horizontal_distance = ray_check_horizontal(cub3d, angle);
	vertical_distance = ray_check_vertically(cub3d, angle);
	if (horizontal_distance < vertical_distance)
		distance = horizontal_distance;
	else
		distance = vertical_distance;
	return (distance);
}

void	draw_ray(t_cub3d *cub3d, t_img *img, float angle, int i)
{
	float	distance;
	t_pos	a;
	t_pos	b;
	//float wallHeight;
	(void) i;
	a.x = cub3d->camera->x;
	a.y = cub3d->camera->y;
	a.color = 0xFFFF00;
	distance = raycasting(cub3d, angle);
	//distance = distance * cos(degrees_to_radians(angle - cub3d->camera->player_angle));
	b.x = a.x + distance * cos(degrees_to_radians(angle));
	b.y = a.y + distance * sin(degrees_to_radians(angle)) * -1; 
	b.color = 0xFFFF00;
	bresenham_algo(a, b, img);
	//wallHeight = cub3d->camera->half_height / distance * scale;
	/*printf("wallHeight: %f, half_H: %f\n", wallHeight, cub3d->camera->half_height);
	t_pos	c;
	t_pos	d;
	c.x = i;
	c.y = cub3d->camera->half_height - wallHeight;
	c.color = 0xffffff;
	d.x = i;
	d.y = cub3d->camera->half_height + wallHeight;
	bresenham_algo(c, d, img);
	c.x = i;
	c.y = 0;
	c.color = 0x0000FF;
	d.x = i;
	d.y = cub3d->camera->half_height - wallHeight;
	bresenham_algo(c, d, img);
	c.x = i;
	c.y = cub3d->camera->half_height + wallHeight;
	c.color = 0x00FF00;
	d.x = i;
	d.y = HEIGHT;
	bresenham_algo(c, d, img);*/
}