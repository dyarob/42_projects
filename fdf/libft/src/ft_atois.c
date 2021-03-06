/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:19:17 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 15:59:21 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atois(char **s)
{
	int					n;
	int					neg;

	n = 0;
	neg = 1;
	while ((!ft_isprint(**s) || **s == ' ') && **s)
		++*s;
	if ((**s == '-' || **s == '+') && ft_isdigit(*(*s + 1)))
	{
		neg = (**s == '-' ? -1 : 1);
		++*s;
	}
	while (ft_isdigit(**s))
	{
		n *= 10;
		n += neg * (**s - 48);
		++*s;
	}
	return (n);
}

