/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:45:23 by avannest          #+#    #+#             */
/*   Updated: 2013/11/27 21:45:30 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (!(s1 > s2 && s2 + n > s1))
		ft_memcpy(s1, s2, n);
	else
		while (n --)
			*((char *)s1 + n) = *((char *)s2 + n);
	return (s1);
}

