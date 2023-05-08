/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:36:38 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/03 12:39:21 by andrferr         ###   ########.fr       */
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
		ft_putendl_fd("You dont have the right amount of elements.", 2);
	}
	else if (err == 3)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong colors configuration on your ceiling or floor.",
			2);
	}
}

void	invalid_texture(char *path)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Couldn't load texture: ", 2);
	ft_putendl_fd(path, 2);
}

void	error_msg_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
