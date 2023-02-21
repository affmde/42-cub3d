/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:38:52 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/07 19:16:29 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				control;
	unsigned long	res;
	int				i;

	i = 0;
	res = 0;
	control = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		control = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807)
		{
			if (control > 0)
				return (-1);
			else
				return (0);
		}
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)res * control);
}
