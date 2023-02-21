/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:55:15 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/02 13:03:15 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	char			*a;
	int				chars_to_cpy;

	if (!dstsize)
		return ((size_t)ft_strlen((char *)src));
	i = ft_strlen(dst);
	if (i >= dstsize)
		return (ft_strlen((char *)src) + dstsize);
	a = (char *)src;
	chars_to_cpy = ft_strlen(dst) + ft_strlen(a);
	while (*a && i < dstsize - 1)
		dst[i++] = *a++;
	dst[i] = '\0';
	return (chars_to_cpy);
}
