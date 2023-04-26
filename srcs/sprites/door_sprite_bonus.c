/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:39:54 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/26 17:27:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	get_door_text(t_cub3d *cub3d, t_sprite *sprite)
{
	(void)cub3d;
	if (sprite->open)
		return (12);
	return (14);
}
