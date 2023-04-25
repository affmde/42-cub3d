/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:03 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 16:59:51 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	delta_time(t_cub3d *cub3d)
{
	struct timeval	t;
	double			elapsed;

	gettimeofday(&t, NULL);
	elapsed = (t.tv_sec - cub3d->time.tv_sec) * 1000;
	elapsed += (t.tv_usec - cub3d->time.tv_usec) / 1000;
	cub3d->d_time = elapsed / 1000;
	cub3d->time = t;
}
