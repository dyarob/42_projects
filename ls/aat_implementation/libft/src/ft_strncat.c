/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:57:07 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:52:53 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t				i;
	size_t				size_s1;

	size_s1 = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[size_s1 + i] = s2[i];
		++i;
	}
	if (i >= n)
		s1[size_s1 + n] = '\0';
	return (s1);
}

