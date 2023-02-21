/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:34:39 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/02 12:31:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			len;
	char			*a;

	if (!dstsize)
		return (ft_strlen((char *)src));
	a = (char *)src;
	len = ft_strlen(a);
	while (--dstsize > 0 && *a)
		*dst++ = *a++;
	*dst = '\0';
	return (len);
}
