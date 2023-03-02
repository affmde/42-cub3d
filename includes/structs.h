/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:46:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/02 16:06:30 by andrferr         ###   ########.fr       */
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

typedef struct s_cub3d
{
	t_list	*textures;
	t_list	*walls;
	t_map	*map;
	t_list	*file_data;
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


#endif
