/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:39:54 by nlonka            #+#    #+#             */
/*   Updated: 2023/04/26 14:39:57 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	get_door_text(t_cub3d *cub3d, t_sprite *sprite)
{
	(void)cub3d;
	if (sprite->open)
		return (10);
	return (11);
}