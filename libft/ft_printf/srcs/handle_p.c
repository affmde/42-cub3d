/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:47:44 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/16 12:20:06 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft.h"

static int	pointer_to_hex(unsigned long dec)
{
	char	hex[16];
	int		index;
	int		ret;

	index = 0;
	while (dec > 0 && index < 16)
	{
		if (dec % 16 < 10)
			hex[index] = (dec % 16) + 48;
		else
			hex[index] = (dec % 16) + 87;
		index++;
		dec /= 16;
	}
	ret = index;
	while (index-- > 0)
		ft_putchar(hex[index]);
	return (ret);
}

int	handle_p(va_list args, char c)
{
	void	*p;
	int		counter;

	p = va_arg(args, void *);
	ft_putchar('0');
	ft_putchar('x');
	if (p == 0)
	{
		ft_putnbr(0);
		counter = 1;
	}
	else
		counter = pointer_to_hex((unsigned long)p);
	return (counter + 2);
}
