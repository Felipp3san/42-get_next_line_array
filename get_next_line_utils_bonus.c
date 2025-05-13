/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:33:41 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/13 12:34:18 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (str[size] != '\0')
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
	total_size = ft_strlen(dest);
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

static size_t	ft_strnlen(char const *s, size_t len)
{
	size_t	size;

	size = 0;
	while (size < len && (*(s + size) != '\0'))
		size++;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	src_size;
	size_t	substr_size;
	size_t	i;

	substr_size = 0;
	src_size = ft_strlen(s);
	if (start < src_size)
		substr_size = ft_strnlen((s + start), len);
	substr = (char *) malloc(substr_size + 1);
	if (substr)
	{
		i = 0;
		while (i < substr_size)
		{
			*(substr + i) = *(s + start + i);
			i++;
		}
		*(substr + i) = '\0';
	}
	return (substr);
}
