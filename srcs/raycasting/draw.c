/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:03:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/14 08:59:54 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void ray_init(t_ray *ray)
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

void	draw(t_cub3d *cub3d)
{
	t_img	*img;
	t_ray	ray;
//	int		i;

	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_new_image(cub3d->ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	cub3d->img = img;
	//draw_minimap(cub3d, img);
	//i = -1;
	//ray.angle = cub3d->camera->player_angle - cub3d->camera->half_fov;
	//while (++i < WIDTH)
	//{
		ray_init(&ray);
		//ray.index = i;
		raycasting(cub3d, &ray);
		//draw_ray(cub3d, img, &ray);
		//draw_col(cub3d, &ray);
		//ray.angle += cub3d->camera->angle_increment;
	//}
	mlx_put_image_to_window(cub3d->ptr, cub3d->win, img->img_ptr, 0, 0);
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

static void	define_wall_texture(t_pos *start, t_pos *end,
	t_cub3d *cub3d, t_ray *ray)
{
	start->x = ray->index;
	start->y = cub3d->camera->half_height - ray->wall_height;
	start->color = 0xffffff;
	end->x = ray->index;
	end->y = cub3d->camera->half_height + ray->wall_height;
}

static void	draw_layer(t_cub3d *cub3d, int wall_height, char *type, t_ray *ray)
{
	t_pos	start;
	t_pos	end;

	if (!ft_strncmp(type, "ceiling", ft_strlen(type)))
	{
		start.x = ray->index;
		start.y = 0;
		start.color = create_rgb(get_wall_color("C", cub3d));
		end.x = ray->index;
		end.y = cub3d->camera->half_height - wall_height;
	}
	else if (!ft_strncmp(type, "floor", ft_strlen(type)))
	{
		start.x = ray->index;
		start.y = cub3d->camera->half_height + wall_height;
		start.color = create_rgb(get_wall_color("F", cub3d));
		end.x = ray->index;
		end.y = HEIGHT;
	}
	else
		define_wall_texture(&start, &end, cub3d, ray);
	bresenham_algo(start, end, cub3d->img);
}

void	draw_col(t_cub3d *cub3d, t_ray *ray)
{
	float	distance;

	distance = ray->distance * cos(degrees_to_radians(ray->angle \
		- cub3d->camera->player_angle));
	ray->wall_height = cub3d->camera->half_height / distance * scale;
	draw_layer(cub3d, ray->wall_height, "ceiling", ray);
	draw_layer(cub3d, ray->wall_height, "floor", ray);
	draw_layer(cub3d, ray->wall_height, "wall", ray);
}
