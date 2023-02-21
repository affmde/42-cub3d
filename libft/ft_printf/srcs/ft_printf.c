/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:49:49 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/16 12:19:47 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft.h"

static int	handle_cases(va_list args, char c, int *count)
{
	if (c == 's')
		*count += handle_s(args, c);
	else if (c == 'i')
		*count += handle_d(args, c);
	else if (c == 'c')
		*count += handle_c(args, c);
	else if (c == 'p')
		*count += handle_p(args, c);
	else if (c == 'x' || c == 'X')
		*count += handle_x(args, c);
	else if (c == 'd')
		*count += handle_d(args, c);
	else if (c == 'u')
		*count += handle_u(args, c);
	return (0);
}

static int	handle_percent(char **str)
{
	ft_putchar('%');
	*str += 1;
	return (1);
}

static int	print(va_list args, char *str)
{
	int	state;
	int	count;

	count = 0;
	state = 0;
	while (*str)
	{
		if (!state)
		{
			if (*str == '%' && *(str + 1) != '%')
				state = 1;
			else if (*str == '%' && *(str + 1) == '%')
				count += handle_percent(&str);
			else
			{
				ft_putchar(*str);
				count++;
			}
		}
		else if (state == 1)
			state = handle_cases(args, *str, &count);
		str++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = print(args, (char *)format);
	va_end(args);
	return (count);
}
