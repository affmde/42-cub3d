/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:28:37 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/28 11:09:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "structs.h"
# include <fcntl.h>

int			file_read(char *path, t_cub3d *cub3d);
int			check_identifier(char *str);
t_cub3d		*cub3d_init(void);
int			parse_elements(char *path, t_cub3d *cub3d);
void		texture_creator(t_textures *texture, char *info);
void		walls_creator(t_walls *wall, char *info);
void		clean_char_arr(char **arr);
void		free_cub3d(t_cub3d *cub3d);
int			parse_map(t_cub3d *cub3d, char *path);


//Parsing
char		*trim_line(char *line, char *str);
void		print_map_elements(t_cub3d *cub3d);		//I CAN REMOVE THIS IN THE END. REMOVE ALSO FILE AND FROM MAKEFILE!!!!

//file validation
int			is_valid_char(char c);
int			is_start_pos(char c);
int			valid_map(t_cub3d *cub3d);
int			file_validity(t_cub3d *cub3d);

#endif
