/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:16:48 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 21:15:17 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int get_color(char **map, int y, int x)
{
	if (map[y][x] == '1')
		return (0xffffff);
	if (map[y][x] == ' ')
		return (0x000000);
	return (0x0880808);
}

static void paint_cube_vertically(t_pos start, t_pos end, t_cub3d *cub3d, t_img *img)
{
	t_pos a;
	t_pos b;
	int	x;

	x = start.x;
	while (x < start.x + 20)
	{
		ft_printf("x: %d - %d\n", x, start.x * 20);
		a = populate_position(x, start.y, 0, get_color(cub3d->map->map, start.y /20, start.x / 20));
		b = populate_position(x, end.y, 0, get_color(cub3d->map->map, start.y / 20, start.x / 20));
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
	while (y < start.y + 20)
	{
		a = populate_position(start.x, y, 0, get_color(cub3d->map->map, start.y /20, start.x / 20));
		b = populate_position(end.x, y, 0, get_color(cub3d->map->map, start.y / 20, start.x / 20));
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
				//start = populate_position(j * 20, i * 20, 0, get_color(cub3d->map->map, i, j));
				//end = populate_position((j + 1) * 20, i * 20, 0, get_color(cub3d->map->map, i, j + 1));
				//bresenham_algo(start, end, img);
				start = populate_position(j * 20, i * 20, 0, get_color(cub3d->map->map, i, j));
				end = populate_position((j + 1) * 20, i * 20, 0, get_color(cub3d->map->map, i, j + 1));
				paint_cube_horizontally(start, end, cub3d, img);
			}
			if (i < cub3d->map->height - 1)
			{
				//start = populate_position(j * 20, i * 20, 0, get_color(cub3d->map->map, i, j));
				//end = populate_position(j * 20, (i + 1) * 20, 0, get_color(cub3d->map->map, i + 1, j));
				//bresenham_algo(start, end, img);
				start = populate_position(j * 20, i * 20, 0, get_color(cub3d->map->map, i, j));
				end = populate_position(j * 20, (i + 1) * 20, 0, get_color(cub3d->map->map, i + 1, j));
				paint_cube_vertically(start, end, cub3d, img);
			}
			/*start = populate_position(j * 20, i * 20, 0, get_color(cub3d->map->map, i, j));
			end = populate_position(j * 20, (i + 1) * 20, 0, get_color(cub3d->map->map, i + 1, j));
			paint_cube(start, end, cub3d, img);*/
			j++;
		}
		i++;
	}
}

void	minimap(t_cub3d *cub3d)
{
	t_img *img;
	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	draw_minimap(cub3d, img);
	mlx_put_image_to_window(cub3d->ptr, cub3d->win, img->img_ptr, 0, 0);
}