/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:59:50 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/15 09:03:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*a;
	size_t		i;

	i = 0;
	a = (const char *)s;
	while (i < n)
	{
		if (a[i] == c)
			return ((void *)&a[i]);
		i++;
	}
	return (0);
}
