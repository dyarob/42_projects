/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:52:06 by avannest          #+#    #+#             */
/*   Updated: 2013/11/21 12:33:25 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void					ft_putchar(char c)
{
	write(1, &c, 1);
}

