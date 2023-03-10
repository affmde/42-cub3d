/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:42:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/04 20:21:32 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(void)
{
	exit(0);
}



int	mlx_handling(t_cub3d *cub3d)
{
	cub3d->ptr = mlx_init();
	cub3d->win = mlx_new_window(cub3d->ptr, WIDTH, HEIGHT, "My window");
	
	mlx_key_hook(cub3d->win, deal_key, cub3d);
	mlx_hook(cub3d->win, 17, 0, close_window, NULL);
	minimap(cub3d);
	mlx_loop(cub3d->ptr);
	return (0);
}