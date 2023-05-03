/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:26:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/03 12:44:19 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc != 2)
		return (ft_putendl_fd("Error\nWrong number of arguments", 2), 1);
	cub3d = cub3d_init();
	if (!cub3d)
		return (ft_putendl_fd("Error\nMalloc failed", 2), 2);
	if (file_read(argv[1], cub3d))
		return (free_cub3d(cub3d), 0);
	if (file_validity(cub3d))
		return (0);
	cub_config_init(cub3d);
	mlx_handling(cub3d);
	free_cub3d(cub3d);
	return (0);
}
