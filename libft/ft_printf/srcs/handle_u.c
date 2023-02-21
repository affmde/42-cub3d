/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:50:40 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/16 12:20:14 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft.h"

static void	print_unsigned(unsigned int num)
{
	char	arr[10];
	int		i;

	i = 0;
	while (num > 0)
	{
		arr[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i-- > 0)
		ft_putchar(arr[i]);
}

int	handle_u(va_list args, char c)
{
	char			*str;
	int				len;
	int				num;
	unsigned int	u_i;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (0);
	num = ft_atoi(str);
	if (num == 0)
	{
		ft_putchar('0');
		free(str);
		return (1);
	}
	u_i = num + 4294967295 + 1;
	print_unsigned(u_i);
	len = ft_nbr_of_digits(u_i);
	free(str);
	return (len);
}
