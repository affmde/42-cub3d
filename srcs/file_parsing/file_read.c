/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:23:17 by andrferr          #+#    #+#             */
/*   Updated: 2023/04/28 08:34:01 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_extension(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (ft_strncmp(&path[i - 4], ".cub", 4))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong file extension.", 2);
		return (1);
	}
	return (0);
}

t_list	*extract_file_data(int fd)
{
	t_list	*file_data;
	char	*line;

	file_data = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "\n", ft_strlen(line)))
			line = trim_line(line, "\n");
		ft_lstadd_back(&file_data, ft_lstnew(ft_strdup(line)));
		ft_strdel(&line);
	}
	return (file_data);
}

static int	handle_parse(t_cub3d *cub3d)
{
	if (parse_map(cub3d))
	{
		ft_putendl_fd("Invalid map configuation", 2);
		return (1);
	}
	if (parse_elements(cub3d))
	{
		ft_putendl_fd("Invalid elements configuration", 2);
		return (1);
	}
	return (0);
}

int	file_read(char *path, t_cub3d *cub3d)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Invalid file name", 2);
		return (1);
	}
	cub3d->file_data = extract_file_data(fd);
	close(fd);
	if (!cub3d->file_data || check_file_extension(path))
	{
		ft_putendl_fd("You have error in the file.", 2);
		return (1);
	}
	if (handle_parse(cub3d))
		return (1);
	return (0);
}
