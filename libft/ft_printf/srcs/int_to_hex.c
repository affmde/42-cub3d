/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:54:07 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/16 12:20:22 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft.h"

static int	pos_dec_to_hex(unsigned int dec, char c)
{
	char	hex[12];
	int		index;
	int		ret;

	index = 0;
	while (dec > 0 && index < 12)
	{
		if (dec % 16 < 10)
			hex[index] = (dec % 16) + 48;
		else
		{
			if (c == 'x')
				hex[index] = (dec % 16) + 87;
			else if (c == 'X')
				hex[index] = (dec % 16) + 55;
		}
		index++;
		dec /= 16;
	}
	ret = index;
	while (index-- > 0)
		ft_putchar(hex[index]);
	return (ret);
}

int	int_to_hex(unsigned int num, char c)
{
	int		count;

	if (num == 0)
	{
		ft_putnbr(0);
		count = 1;
	}
	else
		count = pos_dec_to_hex(num, c);
	return (count);
}
