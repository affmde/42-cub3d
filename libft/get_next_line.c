/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:54:17 by andrferr          #+#    #+#             */
/*   Updated: 2022/11/15 17:31:04 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim_buffer(char *buffer)
{
	int		i;
	char	*aux;
	char	*new_buff;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buff = (char *)malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	if (!new_buff)
		return (NULL);
	i++;
	aux = new_buff;
	while (buffer[i])
		*new_buff++ = buffer[i++];
	*new_buff = '\0';
	free(buffer);
	return (aux);
}

char	*get_line(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i] != '\0')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*new_buffer(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*read_file(int fd, char *buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		buffer = new_buffer(buffer, buf);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	str = get_line(buffer);
	buffer = trim_buffer(buffer);
	return (str);
}
