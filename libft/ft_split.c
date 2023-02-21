/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:07:57 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/28 12:16:35 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *s, char del)
{
	int	count;

	count = 0;
	while (*s)
	{
		if ((*s != del && *(s + 1) == del) || (*s != del && *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static int	ft_letters_count(char *s, char del)
{
	int	count;

	count = 0;
	while (*s && *s != del)
	{
		count++;
		s++;
	}
	return (count);
}

static void	del_str(char **str)
{
	while (*str)
	{
		ft_strdel(str);
		str++;
	}
}

static int	ft_fill_arr(char **arr, int nbr_words, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s && i < nbr_words)
	{
		while (*s == c)
			s++;
		arr[i] = (char *)malloc(sizeof(char)
				* ft_letters_count((char *)s, c) + 1);
		if (!arr[i])
		{
			del_str(arr);
			ft_strdel((char **)&arr);
			return (0);
		}
		j = 0;
		while (*s != c && *s)
			arr[i][j++] = *s++;
		arr[i++][j] = '\0';
		while (*s == c)
			s++;
	}
	arr[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		nbr_words;

	if (!s)
		return (0);
	nbr_words = ft_count_words((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!arr)
		return (NULL);
	if (!ft_fill_arr(arr, nbr_words, s, c))
		return (NULL);
	return (arr);
}
