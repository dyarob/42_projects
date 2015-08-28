/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:11:53 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:31:27 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char					*ft_strmap(char const *s, char (*f)(char))
{
	char				*result;
	char				*mem;

	result = (char *)malloc(ft_strlen(s));
	if (!result)
		return (NULL);
	mem = result;
	while (*s)
	{
		*result = f(*s);
		++s;
		++result;
	}
	*result = '\0';
	return (mem);
}
