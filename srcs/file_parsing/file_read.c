/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:23:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 09:32:32 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	file_read(char *path, t_cub3d *cub3d)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Failed to open the file", 2);
		return (1);
	}
	if (parse_elements(fd, cub3d))
		return (1);
	if (parse_map(cub3d, path))
		return (1);
	return (0);
}
