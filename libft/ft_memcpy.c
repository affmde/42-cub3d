/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:28:40 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/02 11:45:13 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*cdest;
	unsigned char			*csrc;
	size_t					i;

	if (dst == NULL && src == NULL)
		return (0);
	cdest = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*cdest++ = *csrc++;
	return (dst);
}
