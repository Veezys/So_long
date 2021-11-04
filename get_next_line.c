/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breadyma <breadyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:16:41 by breadyma          #+#    #+#             */
/*   Updated: 2021/10/30 18:26:38 by breadyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read(int fd, char *st_str, char *buf)
{
	int		byte;

	byte = 1;
	while (!ft_strchr(st_str, '\n') && byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buf);
			return (0);
		}
		buf[byte] = '\0';
		if (!st_str)
			st_str = ft_substr(buf, 0, byte);
		else
			st_str = ft_strjoin(st_str, buf);
	}
	free(buf);
	return (st_str);
}

char	*ft_return(char *st_str)
{
	char	*str1;
	int		i;

	i = 0;
	while (st_str[i] && st_str[i] != '\n')
		i++;
	if (st_str[i] == '\n')
		i++;
	str1 = ft_substr(st_str, 0, i);
	return (str1);
}

char	*ft_sp(char	*st_str)
{
	char	*rem;
	int		i;

	i = 0;
	while (st_str[i] && st_str[i] != '\n')
		i++;
	i++;
	rem = ft_substr(st_str, i, ft_strlen(st_str));
	free(st_str);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*st_str;
	char		*buf;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	st_str = ft_read(fd, st_str, buf);
	if (!st_str || st_str[0] == '\0')
	{
		free(st_str);
		st_str = 0;
		return (NULL);
	}
	line = ft_return(st_str);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (0);
	}
	st_str = ft_sp(st_str);
	return (line);
}
