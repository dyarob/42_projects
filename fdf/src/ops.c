/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngolovin <ngolovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 16:22:03 by ngolovin          #+#    #+#             */
/*   Updated: 2013/12/22 19:20:16 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_coords.h"
#include <mlx.h>
/*
t_coord2			init_of_points(int x, int y, t_grid map)
{
	t_coord2		p;

	p.x = (x + 1) * DEFAULT_PIXEL_NUMBER + MERGE;
	p.y = (y + 1) * DEFAULT_PIXEL_NUMBER + MERGE; 
	p.z = map.tab[x][y] * DEFAULT_PIXEL_NUMBER / 10;
	return (p);
}
*/
void				draw_column(t_env *e, t_grid map)
{
	int				x;
	int				y;
	t_coord2		a;
	t_coord2		b;

	x = 0;
	y = 0;
	while (x <= map.line)
	{
		while (y <= map.col)
		{
			a = ft_projection(ft_coord3_new(x, y, map));
			if (y + 1 <= map.col)
				b = ft_projection(init_of_points(x + 1, y, map));
			else
				break;
			call_of_draw(e, a, b);
			++y;
		}
		++x;
		y = 0;
	}
}

void				draw_line(t_env *e, t_grid map)
{
	int				x;
	int				y;
	t_coord2		a;
	t_coord2		b;

	x = 0;
	y = 0;
	while (y <= map.col)
	{
		while (x <= map.line)
		{
			a = ft_projection(init_of_points(x, y, map));
			if (x + 1 <= map.line)
				b = ft_projection(init_of_points(x + 1, y, map));
			else
				break;
			call_of_draw(e, a, b);
			++x;
		}
		++y;
		x = 0;
	}
	draw_column(e, map);
}
