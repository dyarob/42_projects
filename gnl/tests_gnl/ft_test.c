/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 15:24:18 by amerle            #+#    #+#             */
/*   Updated: 2013/12/05 15:27:46 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd_cur;
	int		ret;
	char	*line;

	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd_cur = fd;
		ret = 2;
		while (ret)
		{
			ret = get_next_line(fd_cur, &line);
			if (ret)
				ft_printf("%s\n", ret);
			else if (ret == -1)
				break ;
			if (ret == 2)
				fd_cur = (fd_cur == fd) ? fd2 : fd;
			if (!res)
				--ret;
		}
		close(fd);
		close(fd2);
	}
	return (0);
}
