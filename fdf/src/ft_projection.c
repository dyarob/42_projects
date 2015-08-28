/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:47:13 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 22:55:50 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_coords.h"
#include "ft_draw.h"

int ft_sqrt(int nb)
{
		int	root;

			root = 1;
				if (nb <= 0)
							return (0);
					root = 0;
						while (root * root != nb)
								{
											++root;
													if (((root + 1) * (root + 1)) > nb)
																{
																				if ((nb - root * root) <= ((root + 1) * (root + 1) - nb))
																									return (root);
																							else
																												return (root + 1);
			}
	}
	return (root);
}

t_coord2			ft_project(t_coord3 in)
{
	int				tmp_a;
	int				tmp_b;
	t_coord2		out;

	tmp_a = ft_sqrt(in.y * in.y + in.z * in.z) * SIN_A;
	tmp_b = ft_sqrt((in.y * in.y + in.z * in.z) - tmp_a * tmp_a);
	tmp_a = tmp_b * SIN_B;
	tmp_b = ft_sqrt(tmp_b * tmp_b - tmp_a * tmp_a);
	out = ft_coord2_new(X_MARGIN + in.x + tmp_a, Y_MARGIN + in.y - tmp_b);
	return (out);
}

