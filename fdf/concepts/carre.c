/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 21:22:34 by avannest          #+#    #+#             */
/*   Updated: 2013/12/10 19:58:11 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int					main(void)
{
	void			*mlx;
	void			*fenetre;
	int				x;
	int				y;

	mlx = mlx_init();
	fenetre = mlx_new_window(mlx, 2000, 1000, "fenetre");
	sleep(2);
	x = 0;
	while (x <= 0xFF)
	{
		y = 0;
		while (y <= 0xFF)
		{
			mlx_pixel_put(mlx, fenetre, x, y, 0xFF0000 + x * 0x100 + y);
			++ y;
		}
		++ x;
	}
	sleep(5);
	return (0);
}
