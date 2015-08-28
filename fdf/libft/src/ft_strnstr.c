/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:14:59 by avannest          #+#    #+#             */
/*   Updated: 2013/11/30 19:43:51 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char					*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t				size_s2;

	if (!*s2)
		return ((char *)s1);
	size_s2 = ft_strlen(s2);
	if (!*s1 || n < size_s2)
		return (NULL);
	if (*s1 == *s2 && !ft_strncmp(s1, s2, size_s2))
		return ((char *)s1);
	return (ft_strnstr(++ s1, s2, n - 1));
}

