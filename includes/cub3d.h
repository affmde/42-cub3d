/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:28:37 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/05 11:38:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include "defines.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

int			file_read(char *path, t_cub3d *cub3d);
int			check_identifier(char *str);
t_cub3d		*cub3d_init(void);
void		texture_creator(t_textures *texture, char *info);
void		walls_creator(t_walls *wall, char *info);
void		clean_char_arr(char **arr);
void		free_cub3d(t_cub3d *cub3d);
int			parse_map(t_cub3d *cub3d);
char		*get_texture(char *identifier, t_cub3d *cub3d);
t_color		*get_wall_color(char *identifier, t_cub3d *cub3d);
t_camera	*camera_init(t_cub3d *cub3d);
void		validity_error_msg(int err);

//Parsing
char		*trim_line(char *line, char *str);
char		**list_to_matrix(t_list *list);
int			parse_elements(t_cub3d *cub3d);
//file validation
int			is_valid_char(char c);
int			is_start_pos(char c);
int			valid_map(t_cub3d *cub3d);
int			file_validity(t_cub3d *cub3d);
int			elements_validity(t_cub3d *cub3d);
int			is_map_closed(t_cub3d *cub3d, t_map_check *map);
void		map_check_init(t_map_check *map_check);
void		add_values_to_compare(t_map_check *a, t_map_check *b);
int			check_walls_color(t_cub3d *cub3d);
void		check_repeated_walls(t_cub3d *cub3d, t_elements_check *element);
//MLX Handling
int			mlx_handling(t_cub3d *cub3d);
int			deal_key(int keycode, t_cub3d *cub3d);

//Maths
float		degrees_to_radians(int degree);

//Lines
void	put_pixel(t_img *image, int x, int y, int color);
void	bresenham_algo(t_pos pos_0, t_pos pos_1, t_img *image);
t_pos	populate_position(int x, int y, int z, int color);
int		create_rgb(t_color *color);

//RAYCASTING
int		raycasting(t_cub3d *cub3d);


//EXTRAS
void	minimap(t_cub3d *cub3d); //DELETE THIS! IS JUST FOR TESTING THE MAP

#endif
