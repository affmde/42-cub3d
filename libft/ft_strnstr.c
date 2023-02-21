/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:00:20 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/04 10:37:22 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*a;
	char		*b;
	size_t		i;

	a = (char *)haystack;
	b = (char *)needle;
	if (!len && !*b)
		return (a);
	if (!len && *b)
		return (0);
	if (!*b)
		return (a);
	i = 0;
	while (*a && i < len)
	{
		if (*a == *b && !ft_strncmp(a, b, ft_strlen(b))
			&& len >= ft_strlen(b) + i)
			return (a);
		a++;
		i++;
	}
	return (0);
}
