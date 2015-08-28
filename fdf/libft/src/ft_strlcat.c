/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:57:07 by avannest          #+#    #+#             */
/*   Updated: 2013/11/30 19:39:49 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t				i;
	size_t				size_s1;

	size_s1 = ft_strlen(s1);
	if (size_s1 >= n)
		return (ft_strlen(s2) + n);
	i = 0;
	while (s2[i] && i < n - size_s1 - 1)
	{
		s1[i + size_s1] = s2[i];
		++ i;
	}
	s1[i + size_s1] = '\0';
	return (ft_strlen(s2) + size_s1);
}

