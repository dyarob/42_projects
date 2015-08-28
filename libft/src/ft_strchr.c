/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:58:26 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:25:36 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char					*ft_strchr(const char *s, int c)
{
	int					i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		++i;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
