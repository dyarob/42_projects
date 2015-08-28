/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:06:40 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 19:42:48 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void				ft_ritoa(int n, char *res)
{
	if (n > 0)
	{
		ft_ritoa(n / 10, res - 1);
		*res = n % 10 + 48;
	}
}

static int				ft_count_digits(int n)
{
	int					nbr_d;

	if (!n)
		return (1);
	nbr_d = 0;
	if (n < 0)
		++nbr_d;
	while (n)
	{
		n /= 10;
		++nbr_d;
	}
	return (nbr_d);
}

char					*ft_itoa(int n)
{
	int					nbr_d;
	char				*res;

	nbr_d = ft_count_digits(n);
	res = (char *)malloc(nbr_d + 1);
	if (!res)
		return (NULL);
	if (!n)
		*res = '0';
	else if (n == -2147483648)
		ft_strcpy(res, "-2147483648");
	else
	{
		if (n < 0)
		{
			*res = '-';
			ft_ritoa(-1 * n, res + nbr_d - 1);
		}
		else
			ft_ritoa(n, res + nbr_d - 1);
	}
	*(res + nbr_d) = '\0';
	return (res);
}
