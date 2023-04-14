/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:45:40 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/14 21:54:25 by andrferr         ###   ########.fr       */
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

void	texture_render(t_cub3d *cub3d, t_ray *ray)
{
	t_textures *texture;

	double	wall_x;
	int		texture_x;
	double	step;
	double	texture_pos;
	int		texture_y;
	int		color;
	//int		buffer[HEIGHT][WIDTH];

	texture = receive_texture(cub3d, ray->direction);
	if (!texture)
	{
		ft_putendl_fd("Error: couln't get texture", 2);
		exit (1);
	}
	if (ray->direction == EAST || ray->direction == WEST)
		wall_x = cub3d->camera->y + ray->perp_wall_dist  * ray->dir_y;
	else
		wall_x = cub3d->camera->x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)texture->width);
	if ((ray->direction == EAST || ray->direction == WEST) && ray->dir_x > 0)
		texture_x = texture->width - texture_x - 1;
	if ((ray->direction == NORTH || ray->direction == SOUTH) && ray->direction < 0)
		texture_x = texture->width - texture_x - 1;

	step = 1.0 * texture->height / ray->line_height;
	texture_pos = (ray->r_start - HEIGHT / 2 + ray->line_height / 2) * step;
	int	i;
	i = ray->r_start;
	while (i < ray->r_end)
	{
		texture_y = (int)texture_pos & (texture->height - 1);
		texture_pos += step;
		printf("texture: %s texH: %d texY: %d textX: %d val: %d\n", texture->identifier, texture->height, texture_y, texture_x, texture->height * texture_y + texture_x);
		color = texture->img->data[texture->height * texture_y + texture_x];
		//buffer[i][ray->index] = color;
		put_pixel(cub3d->img, ray->index, i, color);
		i++;
	}
}
