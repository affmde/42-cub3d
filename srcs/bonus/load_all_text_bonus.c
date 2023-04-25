/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_all_text_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:34:19 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/25 09:35:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	load_all_bonus_tex(t_cub3d *cub3d)
{
	sprites_config(cub3d);
	weapon_init(cub3d);
	load_aim_texture(cub3d);
	load_bullet_texture(cub3d);
}