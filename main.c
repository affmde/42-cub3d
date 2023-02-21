/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:26:44 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/21 17:24:35 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d *cub3d;
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of argumments.", 2);
		return (1);
	}
	cub3d = cub3d_init();
	file_read(argv[1], cub3d);
	return (0);
}
