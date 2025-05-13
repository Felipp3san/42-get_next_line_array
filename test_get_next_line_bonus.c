/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:34:48 by fde-alme          #+#    #+#             */
/*   Updated: 2025/05/13 12:40:26 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		fd[5];
	int		i;

	//int		fail;
	//fail = 0;
	
	fd[0] = open("test_files/bonus1.txt", O_RDONLY);
	fd[1] = open("test_files/bonus2.txt", O_RDONLY);
	fd[2] = open("test_files/bonus3.txt", O_RDONLY);
	fd[3] = open("test_files/bonus4.txt", O_RDONLY);
	fd[4] = open("test_files/bonus5.txt", O_RDONLY);

	i = 0;
	while (i < 5)
	{
		//while ((str = get_next_line(fd[i], fail)))
		while ((str = get_next_line(fd[i])))
		{
			//if (i == 2)
			//	fail = 1;
			printf("%s", str);
			free(str);
		}
		//fail = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		close(fd[i]);
		i++;
	}
	return (0);
}
