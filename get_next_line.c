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
	char	*new_stash;

	if (!stash)
		return (ft_strjoin("", buffer));
	else
	{
		new_stash = ft_strjoin(stash, buffer);
		free(stash);
		return (new_stash);
	}
}

char	*trim_stash(char *stash, size_t len)
{
	char	*new_stash;
	size_t	stash_size;

	stash_size = ft_strlen(stash);
	if (len == stash_size)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, len, stash_size);
	free(stash);
	return (new_stash);
}

char	*extract_line(char **stash)
{
	char	*line;
	size_t	len;

	len = 0;
	line = NULL;
	while ((*stash)[len] != '\0')
	{
		len++;
		if ((*stash)[len - 1] == '\n')
			break ;
	}
	if (len > 0)
		line = ft_substr(*stash, 0, len);
	*stash = trim_stash(*stash, len);
	return (line);
}

void	free_all(char **stash, char **buffer)
{
	free(*stash);
	*stash = NULL;
	free(*buffer);
	*buffer = NULL;
}

char	*get_next_line(int fd)
{
	static char	*stash;
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
			return (free_all(&buffer, &stash), NULL);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			stash = store_buffer(stash, buffer);
		}
	}
	free(buffer);
	buffer = NULL;
	if (stash)
		return (extract_line(&stash));
	else
		return (NULL);
}
