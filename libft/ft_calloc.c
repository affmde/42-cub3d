/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:04:16 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/15 08:30:12 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (!size || !count)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	i = count * size;
	if (i / size != count)
	{
		free (ptr);
		return (NULL);
	}
	i = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}
