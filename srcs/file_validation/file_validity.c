/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:56:34 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/01 18:51:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	file_validity(t_cub3d *cub3d)
{
	if (valid_map(cub3d))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid map.", 2);
		free_cub3d(cub3d);
		return (1);
	}
	if (elements_validity(cub3d))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("You have repeated elements.", 2);
		free_cub3d(cub3d);
		return (1);
	}
	return (0);
}
