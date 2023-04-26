/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:40:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/26 13:40:33 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	check_blood_anim_over(t_blood *blood)
{
	if (blood->time > BLOOD_SPLATTER_DURATION)
	{
		blood->is_rendering = 0;
		blood->time = 0;
	}
}
