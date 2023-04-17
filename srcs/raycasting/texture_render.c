/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:45:40 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/17 11:13:24 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_textures	*receive_texture(t_cub3d *cub3d, int direction)
{
	if (direction == NORTH)
		return (return_texture("NO", cub3d));
	if (direction == SOUTH)
		return (return_texture("SO", cub3d));
	if (direction == EAST)
		return (return_texture("EA", cub3d));
	if (direction == WEST)
		return (return_texture("WE", cub3d));
	return (NULL);
}

static void	transfer_texture_pixel(t_cub3d *cub3d,
	t_textures *t, int *texture_x)
{
	int		i;
	int		texture_y;
	int		color;
	double	texture_pos;
	double	step;

	step = 1.0 * t->height / cub3d->ray->line_height;
	texture_pos = (cub3d->ray->r_start - HEIGHT / 2
			+ cub3d->ray->line_height / 2) * step;
	i = cub3d->ray->r_start;
	while (i < cub3d->ray->r_end)
	{
		texture_y = (int)texture_pos & (t->height - 1);
		texture_pos += step;
		color = t->img->data[t->height * texture_y + *texture_x];
		put_pixel(cub3d->img, cub3d->ray->index, i, color);
		i++;
	}
}

static void	texture_render(t_cub3d *cub3d, t_ray *ray, int *position)
{
	t_textures	*texture;
	double		wall_x;
	int			texture_x;

	texture = receive_texture(cub3d, ray->direction);
	if (!texture)
	{
		ft_putendl_fd("Error: couln't get texture", 2);
		exit (1);
	}
	if (ray->direction == EAST || ray->direction == WEST)
		wall_x = cub3d->camera->y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = cub3d->camera->x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)texture->width);
	if ((ray->direction == EAST || ray->direction == WEST) && ray->dir_x > 0)
		texture_x = texture->width - texture_x - 1;
	if ((ray->direction == NORTH || ray->direction == SOUTH)
		&& ray->direction < 0)
		texture_x = texture->width - texture_x - 1;
	transfer_texture_pixel(cub3d, texture, &texture_x);
	*position += 1;
}

void	render(t_cub3d *cub3d, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		while (i < ray->r_start)
		{
			if (ray->r_start < 0)
				ray->r_start = 0;
			put_pixel(cub3d->img, ray->index, i, ray->ceiling_color);
			i++;
		}
		while (i < ray->r_end)
			texture_render(cub3d, ray, &i);
		while (i < HEIGHT)
		{
			put_pixel(cub3d->img, ray->index, i, ray->floor_color);
			i++;
		}
		i++;
	}
}
