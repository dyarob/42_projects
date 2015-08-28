/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:12:36 by avannest          #+#    #+#             */
/*   Updated: 2013/12/08 23:39:45 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char					*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == '\0')
		{
			++ i;
			while (i < n)
			{
				s1[i] = '\0';
				++ i;
			}
			return (s1);
		}
		++ i;
	}
	return (s1);
}

