/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:01:25 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/01 11:52:15 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr_num(long n)
{
	if (n < 10)
		return (1);
	return (1 + ft_chr_num(n / 10));
}

static void	ft_create_str(char *str, int index, long val)
{
	str[index] = '\0';
	index--;
	if (val < 0)
	{
		str[0] = '-';
		val = -val;
	}
	while (val > 0)
	{
		str[index] = (val % 10) + 48;
			val /= 10;
			index--;
	}
}

static char	*handle_zero(char *s)
{
	*s++ = '0';
	*s = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	long	n_long;
	char	*new;

	n_long = n;
	if (n_long == 0)
	{
		new = (char *)malloc(sizeof(char) + 1);
		if (!new)
			return (0);
		handle_zero(new);
		return (new);
	}
	if (n_long < 0)
		i = ft_chr_num(-n_long) + 1;
	else
		i = ft_chr_num(n_long);
	new = (char *)malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	ft_create_str(new, i, n_long);
	return (new);
}
