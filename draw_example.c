/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:16:48 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/06 19:41:40 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int get_color(char **map, int y, int x)
{
	if (map[y][x] == '1')
		return (0xffffff);
	if (map[y][x] == ' ')
		return (0xFF000000);
	return (0x0880808);
}

static void paint_cube_vertically(t_pos start, t_pos end, t_cub3d *cub3d, t_img *img)
{
	t_pos a;
	t_pos b;
	int	x;

	x = start.x;
	while (x < start.x + scale)
	{
		a = populate_position(x, start.y, 0, get_color(cub3d->map->map, start.y /scale, start.x / scale));
		b = populate_position(x, end.y, 0, get_color(cub3d->map->map, start.y / scale, start.x / scale));
		bresenham_algo(a, b, img);
		x++;
	}
}

static void paint_cube_horizontally(t_pos start, t_pos end, t_cub3d *cub3d, t_img *img)
{
	t_pos a;
	t_pos b;
	int	y;

	y = start.y;
	while (y < start.y + scale)
	{
		a = populate_position(start.x, y, 0, get_color(cub3d->map->map, start.y /scale, start.x / scale));
		b = populate_position(end.x, y, 0, get_color(cub3d->map->map, start.y / scale, start.x / scale));
		bresenham_algo(a, b, img);
		y++;
	}
}

static void	draw_minimap(t_cub3d *cub3d, t_img *img)
{
	int	i;
	int	j;
	t_pos	start;
	t_pos	end;
	i = 0;
	while (i < cub3d->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(cub3d->map->map[i]))
		{
			if (j < (int)ft_strlen(cub3d->map->map[i]) - 1)
			{
				start = populate_position(j * scale, i * scale, 0, get_color(cub3d->map->map, i, j));
				end = populate_position((j + 1) * scale, i * scale, 0, get_color(cub3d->map->map, i, j + 1));
				paint_cube_horizontally(start, end, cub3d, img);
			}
			if (i < cub3d->map->height - 1)
			{
				start = populate_position(j * scale, i * scale, 0, get_color(cub3d->map->map, i, j));
				end = populate_position(j * scale, (i + 1) * scale, 0, get_color(cub3d->map->map, i + 1, j));
				paint_cube_vertically(start, end, cub3d, img);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_cub3d *cub3d, t_img *img)
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == cub3d->camera->y && j == cub3d->camera->x)
				put_pixel(img, j, i, 0xffffff);
		}
	}
}

float	ray_horizontal_distance(t_cub3d *cub3d, t_pos *start)
{
	t_pos	a;
	int		ya;
	int		xa;
	int		gridX;
	int		gridY;
	
	if (cub3d->camera->player_angle > 180 && cub3d->camera->player_angle < 360) //Ray down Direction
	{
		a.y = (int)(floor(start->y / scale) * scale - 1);
		ya = -64;
	}
	else // Ray Up Direction
	{
		a.y = (int)(floor(start->y / scale) * scale + scale);
		ya = 64;
	}
	xa = (int)(scale / tan(degrees_to_radians(cub3d->camera->player_angle)));
	//gridY = a.y / scale;
	a.x = start->x + (start->y - a.y) / tan(degrees_to_radians(cub3d->camera->player_angle));
	//gridX = a.x / scale;
	while (1)
	{
		gridX = a.x / scale;
		gridY = a.y / scale;
		printf("checking: y: %d x: %d map char: %c\n", gridY, gridX, cub3d->map->map[gridY][gridX]);
		if (cub3d->map->map[gridY][gridX] == '1')
		{
			printf("wall detected on x: %d y: %d\n", gridX, gridY);
			break;
		}
		a.x = (a.x + xa);
		a.y = (a.y + ya);
	}

	float	distance;
	printf("a.x: %d start.x: %d a.y: %d start.y: %d\n", a.x, start->x, a.y, start->y);
	distance = sqrtf(pow(start->x - a.x, 2) + pow(start->y - a.y, 2));
	printf("distance: %f\n", distance);	
	return (distance);
}

float	ray_vertical_distance(t_cub3d *cub3d, t_pos *start)
{
	t_pos	a;
	int		ya;
	int		xa;
	int		gridX;
	int		gridY;
	
	if (cub3d->camera->angle_increment > 90 && cub3d->camera->angle_increment < 270) // Ray turn left
	{
		a.x = (int)(floor(start->x / scale) * scale - 1);
		xa = -64;
	}
	else // ray turn right
	{
		a.x = (int)(floor(start->x / scale) * scale + scale);
		xa = 64;
	}
	ya = (int)(scale * tan(degrees_to_radians(cub3d->camera->player_angle)));
	//gridX = a.x / scale;
	a.y = start->y + (start->x - a.x) / tan(degrees_to_radians(cub3d->camera->player_angle));
	printf("startY: %d startX: %d a.x: %d tan(90): %d\n", start->y, start->x, a.x, (int)tan(degrees_to_radians(cub3d->camera->player_angle - 1)));
	printf("a.y val: %d\n", a.y);
	//gridY = a.y / scale;
	while (1)
	{
		gridX = a.x / scale;
		gridY = a.y / scale;
		printf("vertical.y: %d vertical.x: %d\n", gridY, gridX);
		if (cub3d->map->map[gridY][gridX] == '1')
		{
			printf("Wall found\n");
			break;
		}
		else
			printf("Wall not found\n");
		a.x = a.x + xa;
		a.y = a.y + ya;
	}
	float	distance;
	distance = sqrtf(pow(start->x - a.x, 2) - pow(start->y - a.y, 2));
	return (distance);
}

void	draw_ray(t_cub3d *cub3d, t_img *img, float angle)
{
	//float	horizontal_dist;
	//float	vertical_dist;
	float	smaller_distance;
	t_pos	a;
	t_pos	b;
	
	
	a.x = cub3d->camera->x;
	a.y = cub3d->camera->y;
	a.color = 0xFFFF00;
	//horizontal_dist = ray_horizontal_distance(cub3d, &a);
	//vertical_dist = ray_vertical_distance(cub3d, &a);
	//if (horizontal_dist < vertical_dist)
		//smaller_distance = horizontal_dist;
	//else
		//smaller_distance = vertical_dist;
	smaller_distance = raycasting(cub3d, angle) * scale;
	b.x = a.x + smaller_distance * cos(degrees_to_radians(angle));
	b.y = a.y + smaller_distance * sin(degrees_to_radians(angle)); 
	b.color = 0xFFFF00;
	bresenham_algo(a, b, img);
}

void	minimap(t_cub3d *cub3d)
{
	t_img	*img;
	
	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	cub3d->img = img;
	draw_minimap(cub3d, img);
	draw_player(cub3d, img);
	for(int i = 0; i < WIDTH; i++)
		draw_ray(cub3d, img, cub3d->camera->player_angle- cub3d->camera->half_fov + (i * cub3d->camera->angle_increment));
	//draw_ray(cub3d, img, cub3d->camera->player_angle);
	mlx_put_image_to_window(cub3d->ptr, cub3d->win, img->img_ptr, 0, 0);
}
