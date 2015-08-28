/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 20:56:09 by avannest          #+#    #+#             */
/*   Updated: 2013/12/20 19:22:24 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_buf.h"

#include <unistd.h>
#include <stdarg.h>
/*
int						ft_strlen(char const *s)
{
	int					i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void					ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
*/
static int				ft_perror(void)
{
	return (-1);
}
/*
static int				ft__printf(const char *s)
{

}
*/
int						ft_printf(const char *format, ...)
{
	va_list				ap;
	va_list				ap2;
	t_buf				*buf;

	if(!ft_buf_init(&buf))
		return (ft_perror());
	va_start(ap, format);
	va_copy(ap2, ap);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_b(*format, buf);
		else
		{
			if (*(format + 1) == '%')
				ft_putchar_b('%', buf);
			else if (*(format + 1) == 'c')
				ft_putchar_b(va_arg(ap2, int), buf);
			else if (*(format + 1) == 'd' || *(format + 1) == 'i')
				ft_putnbr_b(va_arg(ap2, int), buf);
			else if (*(format + 1) == 's')
				ft_putstr_b(va_arg(ap2, char*), buf);
			else if (*(format + 1) == 'u')
				ft_putuint_b(va_arg(ap2, unsigned int), buf);
			++format;
		}
		++format;
	}
	write(1, buf->s, buf->i);
	va_end(ap);
	va_end(ap2);
	return (buf->len + buf->i);
}

