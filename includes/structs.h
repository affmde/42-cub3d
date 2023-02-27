/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:46:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 13:35:44 by andrferr         ###   ########.fr       */
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
	t_list *map;
	int		height;
}	t_map;

typedef struct s_cub3d
{
	t_list	*textures;
	t_list	*walls;
	t_map	*map;
}	t_cub3d;

typedef struct s_map_check
{
	int	start_position;
	int	other_chars;
	int	empty_lines;
}	t_map_check;


#endif
