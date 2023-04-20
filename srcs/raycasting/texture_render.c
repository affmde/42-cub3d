/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:45:40 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/20 13:10:33 by andrferr         ###   ########.fr       */
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
	t_textures *t, int *texture_x, int *i)
{
	int		texture_y;
	int		color;
	double	texture_pos;
	double	step;

	step = 1.0 * t->height / cub3d->ray.line_height;
	texture_pos = (cub3d->ray.r_start - HEIGHT / 2
			+ cub3d->ray.line_height / 2) * step;
	while (*i < cub3d->ray.r_end)
	{
		texture_y = (int)texture_pos & (t->height - 1);
		texture_pos += step;
		color = t->img->data[t->height * texture_y + *texture_x];
		put_pixel(&cub3d->img, cub3d->ray.index, *i, color);
		(*i)++;
	}
}

static void	texture_render(t_cub3d *cub3d, int *i)
{
	t_textures	*texture;
	double		wall_x;
	int			texture_x;

	texture = receive_texture(cub3d, cub3d->ray.direction);
	if (!texture)
		error_msg_exit("couldn't get texture");
	if (cub3d->ray.direction == EAST || cub3d->ray.direction == WEST)
		wall_x = cub3d->camera.y + cub3d->ray.perp_wall_dist * cub3d->ray.dir_y;
	else
		wall_x = cub3d->camera.x + cub3d->ray.perp_wall_dist * cub3d->ray.dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)texture->width);
	if ((cub3d->ray.direction == EAST || cub3d->ray.direction == WEST)
		&& cub3d->ray.dir_x > 0)
		texture_x = texture->width - texture_x - 1;
	if ((cub3d->ray.direction == NORTH || cub3d->ray.direction == SOUTH)
		&& cub3d->ray.direction < 0)
		texture_x = texture->width - texture_x - 1;
	transfer_texture_pixel(cub3d, texture, &texture_x, i);
}

void	render(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < cub3d->ray.r_start)
	{
		put_pixel(&cub3d->img, cub3d->ray.index,
			i, cub3d->ray.ceiling_color);
		i++;
	}
	while (i < cub3d->ray.r_end)
		texture_render(cub3d, &i);
	while (i < HEIGHT)
	{
		put_pixel(&cub3d->img, cub3d->ray.index, i, cub3d->ray.floor_color);
		i++;
	}
}
