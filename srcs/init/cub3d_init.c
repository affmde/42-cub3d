/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:15:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/26 16:34:54 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_cub3d	*cub3d_init(void)
{
	t_cub3d	*cub3d;

	cub3d = ft_calloc(1, sizeof(t_cub3d));
	if (!cub3d)
		return (NULL);
	//cub3d->textures = NULL;
	//cub3d->walls = NULL;
	return (cub3d);
}
