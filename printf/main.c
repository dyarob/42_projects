/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:02:21 by avannest          #+#    #+#             */
/*   Updated: 2013/12/20 19:17:23 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <libftprintf.h>

int					main(int ac, char **av)
{
	char *s;

	ft_printf("Test chaine super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue super longue\n");
	ft_printf("Test %%c: c:%c 2:%c C:%c \\n:%c\n", 'c', '2', 'C', '\n');
	ft_printf("Test %%d: 1:%d 132:%d -1:%d 2147483647:%d, -214743648:%d\n", 1, 132, -1, 2147483647, -214743648);
	ft_printf("Test %%i: 1:%d 132:%d -1:%d 2147483647:%d, -214743648:%d\n", 1, 132, -1, 2147483647, -214743648);
	ft_printf("Test %%s: coucou:%s 132:%s COUCOU:%s cou\\ncou:%s \\0:%s NULL:%s\n",
		"coucou", "132", "COUCOU", "cou\ncou", "", NULL);
	ft_printf("Test %%u: 1:%u 132:%u 0:%u 2147483648:%u 4294967295:%u\n", 1, 132, 0, 2147483648, 4294967295);

	//ft_printf("iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii %c", av[1][2000]);
	//printf("%c", av[1][2000]);
	//printf("coucoucoucoucoucoucoucououcoucoucoucoucocuocuocuocucoucouccoucocuoc %s atten\0tion", s);
	//write(1, s, 10);
	//return (ft_printf(av[1]));
	return (0);
}

