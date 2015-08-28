/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 16:08:19 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 18:10:10 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <libft.h>
#include <stdlib.h>

t_map			*ft_map_new(int lines, int columns)
{
	t_map		*ret;

	if (!(ret = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(ret->tab = (int **)malloc(sizeof(int *) * lines)))
		return (NULL);
	ret->lines = 0;
	while (ret->lines < lines)
	{
		if (!(ret->tab[ret->lines] = (int *)malloc(sizeof(int) * columns)))
			return (NULL);
		++ret->lines;
	}
	ret->columns = columns;
	return (ret);
}

void			ft_map_del(t_map **map)
{
	while ((*map)->lines > 0)
	{
		--(*map)->lines;
		free((*map)->tab[(*map)->lines]);
	}
	free((*map)->tab);
	free(*map);
	*map = NULL;
}

void			ft_debug_print(t_map *map)
{
	int			l;
	int			c;

	l = 0;
	while (l < map->lines)
	{
		c = 0;
		while (c < map->columns)
		{
			ft_putnbr(map->tab[l][c]);
			ft_putchar(' ');
			++c;
		}
		ft_putchar('\n');
		++l;
	}
}

