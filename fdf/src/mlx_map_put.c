/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:26:45 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 22:57:48 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_draw.h"

static void		mlx_mappoint_put(void *mlx, void *win, int l, int c, t_map *map)
{
	t_coord2	p;

	p = ft_project(ft_coord3_new(c * P_STEP, l * P_STEP, map->tab[l][c] * 20));
	if (c > 0)
		mlx_line_put(mlx, win, p, ft_project(ft_coord3_new((c - 1) * P_STEP,
					l * P_STEP, map->tab[l][c - 1] * 20)), 0x2040E0);
	if (l < map->lines - 1)
		mlx_line_put(mlx, win, p, ft_project(ft_coord3_new(c * P_STEP,
					(l + 1) * P_STEP, map->tab[l + 1][c] * 20)), 0x2040E0);
	if (c < map->columns - 1)
		mlx_line_put(mlx, win, p, ft_project(ft_coord3_new((c + 1) * P_STEP,
					l * P_STEP, map->tab[l][c + 1] * 20)), 0x2040E0);
}

void			mlx_map_put(void *mlx, void *win, t_map *map)
{
	int			l;
	int			c;

	l = 0;
	while (l < map->lines)
	{
		c = 0;
		while (c < map->columns)
		{
			mlx_mappoint_put(mlx, win, l, c, map);
			++c;
		}
		++l;
	}
}

