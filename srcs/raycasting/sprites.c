/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:18:03 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/20 14:33:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites_config(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	total_sprites;

	total_sprites = 0;
	i = -1;
	while (++i < cub3d->map->height)
	{
		j = -1;
		while (++j < (int)ft_strlen(cub3d->map->map[i]))
		{
			if (cub3d->map->map[i][j] == '2')
				total_sprites++;
		}
	}
	printf("total_sprites: %d\n", total_sprites);
}
