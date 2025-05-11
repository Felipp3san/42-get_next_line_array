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

void	store_buffer(char **stash, char *buffer)
{
	char	*temp;

	if (!(*stash))
	{
		*stash = (char *) malloc(1);
		**stash = '\0';
	}
	temp = *stash;
	*stash = ft_strjoin(*stash, buffer);
	free(temp);
}

void	trim_stash(char **stash, size_t start)
{
	char	*temp;

	temp = *stash;
	*stash = ft_substr(*stash, start, ft_strlen(*stash));
	free(temp);
}

char	*extract_line(char **stash)
{
	char	*str;
	size_t	end;

	if (!(*stash))
		return (NULL);
	end = 0;
	while ((*stash)[end] != '\0')
	{
		end++;
		if ((*stash)[end - 1] == '\n')
			break ;
	}
	if (end == 0)
	{
		free(*stash);
		return (NULL);
	}
	str = ft_substr(*stash, 0, end);
	trim_stash(stash, end);
	return (str);
}

void	free_all(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
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
	*buffer = '\0';
	read_bytes = 1;
	while (read_bytes && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_all(buffer, stash), NULL);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			store_buffer(&stash, buffer);
		}
	}
	free(buffer);
	line = extract_line(&stash);
	return (line);
}
