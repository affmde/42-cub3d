/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:37:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/28 12:54:41 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments.", 2);
		return (1);
	}
	cub3d = cub3d_init();
	if (file_read(argv[1], cub3d))
	{
		free_cub3d(cub3d);
		return (0);
	}
	if (file_validity(cub3d))
		return (0);
	cub_config_init(cub3d);
	mlx_handling(cub3d);
	free_cub3d(cub3d);
	return (0);
}
