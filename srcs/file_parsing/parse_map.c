/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:57:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/26 18:44:26 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_map(t_cub3d *cub3d, int fd)
{
	char	*line;
	
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		ft_lstadd_back(&cub3d->map, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	return (0);
}