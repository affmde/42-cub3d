/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:55:26 by andrferr          #+#    #+#             */
/*   Updated: 2022/10/28 12:45:19 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	int		len;
	int		i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen((char *)s1);
	while (*s1 && ft_strchr(set, s1[len - 1]))
		len--;
	a = (char *)malloc(sizeof(char) * len + 1);
	if (!a)
		return (0);
	i = 0;
	while (i < len)
	{
		a[i] = *s1++;
		i++;
	}
	a[i] = '\0';
	return (a);
}
