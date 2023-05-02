/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:33:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/05/02 11:07:04 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_start_detector(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '1'))
			return (1);
		i++;
	}
	return (0);
}

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
	else if (map_start_detector(str) == 0)
		return (4);
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

char	**list_to_matrix(t_list *list)
{
	t_list	*temp;
	char	**arr;
	int		height;
	int		i;

	height = ft_lstsize(list);
	arr = ft_calloc(height + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	temp = list;
	i = 0;
	while (temp)
	{
		arr[i] = ft_strdup(temp->content);
		if (!arr[i])
			return (NULL);
		i++;
		temp = temp->next;
	}
	return (arr);
}

int	contains_non_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
