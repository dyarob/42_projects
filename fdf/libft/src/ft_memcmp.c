/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:49:21 by avannest          #+#    #+#             */
/*   Updated: 2013/11/23 14:27:01 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*((char *)s1 + i) != *((char *)s2 + i))
			return (*((char *)s1 + i) - *((char *)s2 + i));
		++ i;
	}
	return (0);
}

