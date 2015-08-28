/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 21:22:34 by avannest          #+#    #+#             */
/*   Updated: 2013/12/21 13:02:33 by avannest         ###   ########.fr       */
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
	//t_coord2		*p1;
	//t_coord2		*p2;

	if (!(mlx = mlx_init()))
		return (-1);
	if (!(fenetre = mlx_new_window(mlx, 2000, 1000, "fenetre")))
		return (-1);;
	sleep(1);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(100, 600), 0xE06000);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(0, 0), 0xE06000);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(600, 300), 0xE06000);
	//diagonal
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(100, 350), 0xE06000);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(100, 250), 0xE06000);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(0, 350), 0xE06000);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(0, 250), 0xE06000);
	// horizontal
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(0, 300), 0xE06000);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(600, 100), 0xE06000);
	//mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(50, 100), 0xE060A0);
	// vertical straight
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(50, 0), 0xA060A0);
	mlx_line_put(mlx, fenetre, ft_coord2_new(50, 300), ft_coord2_new(50, 1000), 0x0060A0);
	//point
	mlx_line_put(mlx, fenetre, ft_coord2_new(0, 0), ft_coord2_new(0, 0), 0x0060A0);
	sleep(15);
	return (0);
}
