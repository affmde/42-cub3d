/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:23:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/27 20:22:16 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_file_extension(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (ft_strncmp(&path[i - 4], ".cub", 4))
	{
		ft_putendl_fd("Wrong file extension.", 2);
		return (1);
	}
	return (0);
}

int	file_read(char *path, t_cub3d *cub3d)
{
	if (check_file_extension(path))
		return (1);
	if (parse_map(cub3d, path))
		return (1);
	if (parse_elements(path, cub3d))
		return (1);
	if (file_validity(cub3d))
		return (1);
	return (0);
}
