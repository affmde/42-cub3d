/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:26:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/13 09:17:41 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d *cub3d;
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments.", 2);
		return (1);
	}
	cub3d = cub3d_init();
	if(file_read(argv[1], cub3d))
	{
		free_cub3d(cub3d);
		return (0);
	}
	if (file_validity(cub3d))
		return (0);
	cub3d->camera = camera_init(cub3d);
	if (!cub3d->camera)
	{
		free_cub3d(cub3d);
		return (0);
	}

	mlx_handling(cub3d);
	free_cub3d(cub3d);
	return (0);
}