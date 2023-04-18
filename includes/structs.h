/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:46:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/18 17:42:31 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	full_color;
}	t_color;

typedef struct s_position
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pos;

typedef struct s_textures
{
	char			*identifier;
	char			*path;
	struct s_img	*img;
	int				height;
	int				width;
}	t_textures;


typedef struct s_walls
{
	char			*identifier;
	t_color			*color;
	struct s_img	*img;
	int				height;
	int				wall;
}	t_walls;

typedef struct s_map
{
	char	**map;
	int		height;
	int		max_length;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}	t_img;

typedef struct s_ray
{
	int		index;
	int		wall_height;
	float	distance;
	float	wall_hit_x;
	float	wall_hit_y;
	t_pos	start;
	t_pos	end;

	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		direction;
	int		hit;
	double	perp_wall_dist;
	int		line_height;
	int		r_start;
	int		r_end;
	int		ceiling_color;
	int		floor_color;
}		t_ray;

typedef struct s_camera
{
	float	x;
	float	y;
	float	player_angle;
	float	half_height;
	double	plane_x;
	double	plane_y;
	int		direction;
	double	d_fov;
	double	dir_x;
	double	dir_y;
	double	cam_x;
}	t_camera;

typedef struct s_cub3d
{
	t_list				*textures;
	t_list				*walls;
	t_map				*map;
	t_list				*file_data;
	void				*ptr;
	void				*win;
	t_img				img;
	t_camera			camera;
	int					mouse_x;
	struct s_ray		ray;
}	t_cub3d;

typedef struct s_map_check
{
	int		start_position;
	int		other_chars;
	int		empty_lines;
	int		ones;
	int		zeros;
	int		spaces;
	int		hats;
	char	**map;
}	t_map_check;

typedef struct s_elements_check
{
	int	n;
	int	s;
	int	e;
	int	w;
	int	f;
	int	c;
}	t_elements_check;

typedef struct s_line_params
{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	error;
	int	offset;
}		t_params;

#endif
