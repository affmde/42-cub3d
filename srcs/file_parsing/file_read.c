/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:23:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 10:05:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	file_read(char *path, t_cub3d *cub3d)
{
	if (parse_map(cub3d, path))
		return (1);
	if (parse_elements(path, cub3d))
		return (1);
	return (0);
}
