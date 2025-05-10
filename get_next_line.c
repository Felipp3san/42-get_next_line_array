/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:22:12 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/08 23:10:40 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*store_buffer(char *stash, char *buffer)
{
	if (!stash)
	{
		stash = (char *) malloc(1);
		*stash = '\0';
	}
	return (ft_strjoin(stash, buffer));
}

char	*extract_line(char *stash)
{
	char	*str;
	size_t	end;

	if (!stash)
		return (NULL);
	end = 0;
	while (stash[end] != '\0')
	{
		end++;
		if (stash[end - 1] == '\n')
			break;
	}
	str = ft_substr(stash, 0, end);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			read_bytes;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes && ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			stash = store_buffer(stash, buffer);
		}
	}
	free(buffer);
	line = extract_line(stash);
	return (line);
}
