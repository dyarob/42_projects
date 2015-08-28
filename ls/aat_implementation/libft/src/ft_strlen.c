/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:06:44 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:51:21 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t					ft_strlen(const char *s)
{
	size_t				i;

	i = 0;
	while (*(s + i))
		++i;
	return (i);
}
