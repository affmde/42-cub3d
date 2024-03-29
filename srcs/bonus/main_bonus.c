/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:37:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 19:18:51 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
