/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:41:30 by avannest          #+#    #+#             */
/*   Updated: 2013/12/07 14:13:38 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include "get_next_line.h"

int					main(void)
{
	char			*line;
	int				i;

	i = 1;
	while (get_next_line(0, &line) == 1)
	{
		ft_putstr("ligne ");
		ft_putnbr(i);
		ft_putstr(" ->");
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
		++i;
	}
	return (0);
}
