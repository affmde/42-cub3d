/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:03:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/14 21:08:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ray_init(t_ray *ray)
{
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->direction = 0;
	ray->perp_wall_dist = 0;
	ray->r_start = 0;
	ray->r_end = 0;
	ray->wall_hit_x = 0;
}

void	draw_ray(t_cub3d *cub3d, t_img *img, t_ray *ray)
{
	float	distance;

	ray->start.x = cub3d->camera->x;
	ray->start.y = cub3d->camera->y;
	ray->start.color = 0xFFFF00;
	distance = ray->distance;
	ray->end.x = ray->start.x + distance * cos(degrees_to_radians(ray->angle));
	ray->end.y = ray->start.y + distance * sin(degrees_to_radians(ray->angle));
	ray->end.color = 0xFFFF00;
	bresenham_algo(ray->start, ray->end, img);
}

static void	render_texture(t_cub3d *cub3d, t_ray *ray, int *i)
{
	if (ray->r_start < 0)
		ray->r_start = 0;
	//put_pixel(cub3d->img, ray->index, *i, 0xffffff);
	texture_render(cub3d, ray);
	(*i)++;
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
			put_pixel(cub3d->img, ray->index, i,
				create_rgb(get_wall_color("C", cub3d)));
			i++;
		}
		while (i < ray->r_end)
			render_texture(cub3d, ray, &i);
		while (i < HEIGHT)
		{
			put_pixel(cub3d->img, ray->index, i,
				create_rgb(get_wall_color("F", cub3d)));
			i++;
		}
		i++;
	}
}

void	draw(t_cub3d *cub3d)
{
	t_img	*img;
	t_ray	ray;

	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_l, &img->endian);
	cub3d->img = img;
	ray_init(&ray);
	raycasting(cub3d, &ray);
	//draw_minimap(cub3d, img);
	//draw_ray(cub3d, img, &ray);
	//mlx_put_image_to_window(cub3d->ptr, cub3d->win, img->img_ptr, 0, 0);
}
