/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:26:39 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/16 11:18:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	populate(char *a, char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[start + i])
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	size;

	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
	{
		a = (char *)malloc(sizeof(char) + 1);
		if (!a)
			return (NULL);
		a[0] = '\0';
		return (a);
	}
	size = (ft_min((int) len, ft_strlen(s) - start));
	a = (char *)malloc(sizeof(char) * size + 1);
	if (!a)
		return (0);
	populate(a, s, start, len);
	return (a);
}
