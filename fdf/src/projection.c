/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngolovin <ngolovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:05:29 by ngolovin          #+#    #+#             */
/*   Updated: 2013/12/22 12:30:38 by ngolovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor			projection(t_cor p)
{
	int				temp_a;
	int				temp_b;
	int				val;

	val = SIN_VAL;
	temp_a = ft_sqrt(p.y * p.y + p.z * p.z) * val / 10;
	temp_b = ft_sqrt((p.y * p.y + p.z * p.z) - temp_a * temp_a);
	temp_a = temp_b * val / 10;
	temp_b = ft_sqrt(temp_b * temp_b - temp_a * temp_a);
	p.x = p.x - temp_a;
	p.y = p.y - temp_b;
	return (p);
}
