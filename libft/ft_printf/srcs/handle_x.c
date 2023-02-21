/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:54:19 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/16 12:20:18 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft.h"

int	handle_x(va_list args, char c)
{
	int	num;
	int	count;

	num = va_arg(args, unsigned int);
	count = int_to_hex(num, c);
	return (count);
}
