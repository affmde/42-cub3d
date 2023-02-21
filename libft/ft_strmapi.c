/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:08:54 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/03 12:13:00 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*a;
	int					len;
	unsigned int		i;

	if (!s)
		return (0);
	len = ft_strlen((char *)s);
	a = (char *)malloc(sizeof(char) * len + 1);
	if (!a)
		return (NULL);
	i = 0;
	while (s[i])
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
