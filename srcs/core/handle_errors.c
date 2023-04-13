/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:36:38 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/13 08:33:55 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validity_error_msg(int err)
{
	if (err == 1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid map.", 2);
	}
	else if (err == 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("You have repeated elements.", 2);
	}
	else if (err == 3)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong colors configuration on your ceiling or floor.", 2);
	}
}

void	invalid_texture(char *path)
{
	ft_putendl_fd("Error: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": couldn't load texture\n", 2);
}