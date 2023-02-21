/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:58:57 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/15 12:43:02 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	handle_d(va_list args, char c);
int	handle_c(va_list args, char c);
int	handle_s(va_list args, char c);
int	handle_p(va_list args, char c);
int	handle_x(va_list args, char c);
int	handle_u(va_list args, char c);
int	power_of(int num, int power);
int	int_to_hex(unsigned int num, char c);

#endif
