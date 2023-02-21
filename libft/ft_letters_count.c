/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:56:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/17 12:04:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_letter_count(char *s, char del)
{
	int	count;

	count = 0;
	if (del)
	{
		while (*s && *s != del)
		{
			count++;
			s++;
		}
	}
	else
	{
		while (*s)
		{
			count++;
			s++;
		}
	}
	return (count);
}
