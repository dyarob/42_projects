/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:22:22 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:24:43 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_putpnbr(int n)
{
	if (n > 0)
	{
		ft_putpnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

void					ft_putnbr(int n)
{
	if (!n)
		ft_putchar('0');
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putpnbr(-1 * n);
	}
	else
		ft_putpnbr(n);
}
