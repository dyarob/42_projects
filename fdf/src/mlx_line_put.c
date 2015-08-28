/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_line_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 19:59:27 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 15:01:32 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_coords.h"
#include <mlx.h>
#include <stdio.h>

unsigned int		ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	else
		return (n);
}

static void			mlx_mostly_horizontal(void *mlx_ptr, void *win_ptr,
	t_coord2 p1, t_coord2 p2, int color)
{
	int				x;

	x = p1.x;
	while (x <= p2.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x,
			p1.y + (p2.y - p1.y) * (x - p1.x) / (p2.x - p1.x), color);
		++x;
	}
}

static void			mlx_mostly_vertical(void *mlx_ptr, void *win_ptr,
	t_coord2 p1, t_coord2 p2, int color)
{
	int				y;

	y = p1.y;
	while (y <= p2.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr,
			p1.x + (p2.x - p1.x) * (y - p1.y) / (p2.y - p1.y), y, color);
		++y;
	}
}

void				mlx_line_put(void *mlx_ptr, void *win_ptr,
	t_coord2 p1, t_coord2 p2, int color)
{
	if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y))
	{
		if (p1.x < p2.x)
			mlx_mostly_horizontal(mlx_ptr, win_ptr, p1, p2, color);
		else
			mlx_mostly_horizontal(mlx_ptr, win_ptr, p2, p1, color);
	}
	else
	{
		if (p2.y > p1.y)
			mlx_mostly_vertical(mlx_ptr, win_ptr, p1, p2, color);
		else if (p2.y != p1.y)
			mlx_mostly_vertical(mlx_ptr, win_ptr, p2, p1, color);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, p1.x, p1.y, color);
	}
}

