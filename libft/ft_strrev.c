/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:02:09 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/28 12:16:14 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strrev(char *str)
{
	int	med;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	med = len / 2;
	while (i < med)
	{
		swap(&str[i], &str[len - 1 - i]);
		i++;
	}
	return (str);
}
