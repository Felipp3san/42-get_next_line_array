/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:01:21 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/08 23:10:04 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			s_len;
	size_t			i;

	i = 0;
	s_len = ft_strlen(s);
	uc = (unsigned char) c;
	while (i <= s_len)
	{
		if (s[i] == uc)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str && str[size])
		size++;
	return (size);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*new_str;
	size_t	total_size;
	size_t	i;

	if (!dest || !src)
		return (NULL);
	total_size = 0;
	total_size += ft_strlen(dest);
	total_size += ft_strlen(src);
	new_str = (char *) malloc(total_size + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*dest)
		new_str[i++] = *(dest++);
	while (*src)
		new_str[i++] = *(src++);
	new_str[total_size] = '\0';
	return (new_str);
}

char	*ft_substr(char *src, size_t start, size_t end)
{
	char	*new_str;
	size_t	i;

	new_str = (char *) malloc((end - start) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (start < end)
		new_str[i++] = src[start++];
	new_str[i] = '\0';
	return (new_str);
}
