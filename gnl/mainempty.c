/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:41:30 by avannest          #+#    #+#             */
/*   Updated: 2013/12/07 14:01:24 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include "get_next_line.h"

int					main(void)
{
	char			*line;
	int				fd;
	int				i;

	fd = open("emptyfile", O_RDONLY);
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		//ft_putstr("Attention la c'est la ligne ->");
		ft_putstr("ligne ");
		ft_putnbr(i);
		ft_putstr(" ->");
		ft_putstr(line);
		ft_putstr("\n");
		//ft_putstr("<-\n");
		free(line);
		++i;
	}
	return (0);
}
