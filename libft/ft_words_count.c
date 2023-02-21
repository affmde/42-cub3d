/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:45:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/17 12:03:50 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words_count(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if ((!ft_isspace(*s) && ft_isspace(*(s + 1)))
			|| (!ft_isspace(*s) && *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}
