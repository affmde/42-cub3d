/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:46:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/26 20:21:54 by andrferr         ###   ########.fr       */
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


typedef struct s_cub3d
{
	t_list	*textures;
	t_list	*walls;
	t_list	*map;
}	t_cub3d;

typedef struct s_map_check
{
	int	zeros;
	int	ones;
	int	start_position;
}	t_map_check

#endif
