/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:02:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/26 13:14:20 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

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
	double	*dir_x;
	double	*dir_y;
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
	float	half_height;
	double	plane_x;
	double	plane_y;
	int		direction;
	double	d_fov;
	double	dir_x;
	double	dir_y;
	double	cam_x;
}	t_camera;

typedef struct s_movement
{
	int	move_forward;
	int	move_backwards;
	int	move_right;
	int	move_left;
	int	turn_right;
	int	turn_left;
}	t_movement;

typedef struct s_sprite
{
	double	x;
	double	y;
	int		texture;
	double	distance;
	int		order;
	char	identifier;
	int		alive;
	double	anim_frame;
	int		hit;
	int		is_attacking;
	int		open;

}		t_sprite;

typedef struct sprites_manager
{
	t_list			*sprites_list;
	int				total_sprites;
	int				enemies_left;
	t_textures		sprite_texture[16];
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				sprite_width;
	int				color;

}	t_sprites_manager;

typedef struct s_weapon
{
	t_textures	*gun;
	t_textures	b_text;
	int			max_bullets;
	int			bullets;
	int			state;
	double		anim_frame;
}	t_weapon;

typedef struct s_blood
{
	t_textures	blood_texture[3];
	int			index;
	int			is_rendering;
	double		time;
}	t_blood;

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
	t_movement			movement;
	double				*z_buffer;
	t_sprites_manager	sp_manager;
	t_weapon			weapon;
	t_textures			aim;
	t_blood				blood;
	double				d_time;
	struct timeval		time;
	int					health;
	int					won;
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
	int		enemies;
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
