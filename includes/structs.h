/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:46:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/06 14:46:06 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_textures
{
	char	*identifier;
	char	*path;
}	t_textures;


typedef struct s_walls
{
	char	*identifier;
	t_color	*color;
}	t_walls;

typedef struct s_map
{
	char	**map;
	int		height;
	int		max_length;
}	t_map;

typedef struct s_ray
{

}	t_ray;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}	t_img;

typedef struct s_camera
{
	int		fov;
	float	half_fov;
	float	angle_increment;
	int		precision;
	int		x;
	int		y;
	float	player_angle;
	float	half_width;
	float	half_height;
	float	distance_to_plane;
}	t_camera;

typedef struct s_cub3d
{
	t_list		*textures;
	t_list		*walls;
	t_map		*map;
	t_list		*file_data;
	void		*ptr;
	void		*win;
	t_img		*img;
	t_camera	*camera;
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

typedef struct s_position
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pos;

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
