/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:41:30 by avannest          #+#    #+#             */
/*   Updated: 2013/12/08 22:41:23 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include <unistd.h>
#include "get_next_line.h"

int					main(void)
{
	char			*line;
	int				fd;
	int				i;

	i = 0;
	while ( i < 10)
	{
		fd = open("Lorem", O_RDONLY);

		while (get_next_line(fd, &line) == 1)
		{
			//ft_putstr("Attention la c'est la ligne ->");
			ft_putstr(line);
			ft_putstr("\n");
			//ft_putstr("<-\n");
			free(line);
		}
		close(fd);
		++i;
	}
	return (0);
}
