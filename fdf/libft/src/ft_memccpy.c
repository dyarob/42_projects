/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:49:21 by avannest          #+#    #+#             */
/*   Updated: 2013/11/29 16:21:05 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		if (((char *)s2)[i] == (char)c)
			return ((char *)s1 + i + 1);
		++ i;
	}
	return (NULL);
}

