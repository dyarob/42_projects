/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:22:22 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:24:47 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_putpnbr_fd(int n, int fd)
{
	if (n > 0)
	{
		ft_putpnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}

void					ft_putnbr_fd(int n, int fd)
{
	if (!n)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putpnbr_fd(-1 * n, fd);
	}
	else
		ft_putpnbr_fd(n, fd);
}
