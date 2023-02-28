/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:33:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/28 10:19:48 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_identifier(char *str)
{
	if (!ft_strncmp("NO ", str, 3))
		return (1);
	else if (!ft_strncmp("SO ", str, 3))
		return (1);
	else if (!ft_strncmp("WE ", str, 3))
		return (1);
	else if (!ft_strncmp("EA ", str, 3))
		return (1);
	else if (!ft_strncmp("F ", str, 2))
		return (2);
	else if (!ft_strncmp("C ", str, 2))
		return (2);
	else if (!ft_strncmp(str, "\n", ft_strlen(str)))
		return (3);
	else
		return (0);
}


char	*trim_line(char *line, char *str)
{
	char	*new;

	new = ft_strtrim(line, str);
	if (!new)
		return (NULL);
	free(line);
	return (new);
}