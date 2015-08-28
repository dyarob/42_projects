/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:58:26 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:53:59 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char					*ft_strrchr(const char *s, int c)
{
	int					i;
	char				*mem;

	mem = NULL;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			mem = (char *)(s + i);
		++i;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (mem);
}

