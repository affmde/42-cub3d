/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:23:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/21 17:23:55 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	file_read(char *path, t_cub3d *cub3d)
{
	int	fd;
	char *line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Failed to open the file", 2);
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);

	}
	(void)cub3d;
	close(fd);
	return (0);
}
