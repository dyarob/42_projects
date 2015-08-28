/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 21:22:34 by avannest          #+#    #+#             */
/*   Updated: 2013/12/21 22:43:14 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_coords.h"
#include "ft_draw.h"
#include <unistd.h>
#include <mlx.h>

int					main(void)
{
	void			*mlx;
	void			*fenetre;
	t_coord3		p1;
	t_coord3		p2;
	t_coord3		p3;
	t_coord3		p4;

	if (!(mlx = mlx_init()))
		return (-1);
	if (!(fenetre = mlx_new_window(mlx, 2000, 1000, "fenetre")))
		return (-1);
	sleep(1);

	p1 = ft_coord3_new(100, 100, 1);
	p2 = ft_coord3_new(200, 100, 42);
	p3 = ft_coord3_new(100, 200, 1);
	p4 = ft_coord3_new(200, 200, 62);
	mlx_line_put(mlx, fenetre, ft_coord3to2(p1), ft_coord3to2(p2), 0xFF0050);
	mlx_line_put(mlx, fenetre, ft_coord3to2(p4), ft_coord3to2(p2), 0xFF0050);
	mlx_line_put(mlx, fenetre, ft_coord3to2(p1), ft_coord3to2(p3), 0xFF0050);
	mlx_line_put(mlx, fenetre, ft_coord3to2(p3), ft_coord3to2(p4), 0xFF0050);
	mlx_line_put(mlx, fenetre, ft_project(p1), ft_project(p2), 0x0060A0);
	mlx_line_put(mlx, fenetre, ft_project(p1), ft_project(p3), 0x0060A0);
	mlx_line_put(mlx, fenetre, ft_project(p4), ft_project(p2), 0x0060A0);
	mlx_line_put(mlx, fenetre, ft_project(p3), ft_project(p4), 0x0060A0);

	sleep(15);
	return (0);
}
