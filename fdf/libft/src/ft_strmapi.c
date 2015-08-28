/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:11:53 by avannest          #+#    #+#             */
/*   Updated: 2013/12/01 19:18:46 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char					*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		i;

	result = (char *)malloc(ft_strlen(s));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		++ i;
	}
	result[i] = '\0';
	return (result);
}

