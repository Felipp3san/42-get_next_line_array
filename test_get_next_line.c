/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:20:33 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/08 21:29:02 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	char	*str;
	int		fd;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd != -1)
			{
				while ((str = get_next_line(fd)))
					printf("%s\n", str);
				close(fd);
			}
			i++;
		}
	}
	return (0);
}
