/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:06:45 by andrferr          #+#    #+#             */
/*   Updated: 2022/10/31 15:27:41 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*b;
	int		len;

	len = ft_strlen((char *)s1);
	a = (char *)malloc(sizeof(char) * len + 1);
	b = a;
	if (!a)
		return (0);
	while (*s1)
		*a++ = *s1++;
	*a = '\0';
	return (b);
}
