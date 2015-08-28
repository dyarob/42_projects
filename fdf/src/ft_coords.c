/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 21:24:22 by avannest          #+#    #+#             */
/*   Updated: 2013/12/21 22:43:24 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_coords.h"
#include <stdlib.h>

t_coord2		ft_coord2_new(int x, int y)
{
	t_coord2	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_coord3		ft_coord3_new(int x, int y, int z)
{
	t_coord3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_coord2		ft_coord3to2(t_coord3 p)
{
	return (ft_coord2_new(p.x, p.y));
}

