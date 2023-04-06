/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:16:48 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/06 21:47:30 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/*static int get_color(char **map, int y, int x)
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
}*/

/*static void	draw_minimap(t_cub3d *cub3d, t_img *img)
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
}*/

void	minimap(t_cub3d *cub3d)
{
	t_img	*img;
	int		i;
	
	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	cub3d->img = img;
	//draw_minimap(cub3d, img);
	i = -1;
	while (++i < WIDTH)
		draw_ray(cub3d, img, cub3d->camera->player_angle- cub3d->camera->half_fov + (i * cub3d->camera->angle_increment), i);
	mlx_put_image_to_window(cub3d->ptr, cub3d->win, img->img_ptr, 0, 0);
}
