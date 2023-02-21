/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:44:24 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/04 10:45:32 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	char	*b;

	if (!s1 || !s2)
		return (0);
	a = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	if (!a)
		return (NULL);
	b = a;
	while (*s1)
		*a++ = *s1++;
	while (*s2)
		*a++ = *s2++;
	*a = '\0';
	return (b);
}
