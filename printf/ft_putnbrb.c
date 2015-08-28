/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:22:22 by avannest          #+#    #+#             */
/*   Updated: 2013/12/20 19:11:16 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"

void					ft_putchar_b(char c, t_buf *b)
{
	b->s[b->i] = c;
	ft_buf_inc(b);
}

void					ft_putstr_b(char *s, t_buf *b)
{
	int					i;

	if (s)
	{
		i = b->i;
		while (s[b->i - i])
		{
			b->s[b->i] = s[b->i - i];
			ft_buf_inc(b);
		}
	}
	else
		ft_putstr_b("(null)", b);
}

/*
** not functional without buf_inc
*/
void					ft_write_b(t_buf *b, char *s, int n)
{
	int					i;

	i = 0;
	while (i < n)
	{
		b->s[b->i + i] = s[i];
		++i;
	}
	b->i += i;
}

static void				ft_putpnbr_b(unsigned int n, t_buf *b)
{
	if (n > 0)
	{
		ft_putpnbr_b(n / 10, b);
		ft_putchar_b(n % 10 + 48, b);
	}
}

void					ft_putuint_b(unsigned int n, t_buf *b)
{
	if (!n)
		ft_putchar_b('0', b);
	else
		ft_putpnbr_b(n, b);
}

void					ft_putnbr_b(int n, t_buf *b)
{
	if (!n)
		ft_putchar_b('0', b);
	else if (n == -2147483648)
		ft_putstr_b("-2147483648", b);
	else if (n < 0)
	{
		ft_putchar_b('-', b);
		ft_putpnbr_b(-1 * n, b);
	}
	else
		ft_putpnbr_b(n, b);
}

