/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:30:08 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/16 12:20:01 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft.h"

int	handle_d(va_list args, char c)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (0);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
