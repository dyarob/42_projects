/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:40:57 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:30:13 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char					*ft_strjoin(char const *s1, char const *s2)
{
	int					len;
	int					size_s1;
	char				*res;

	size_s1 = ft_strlen(s1);
	len = size_s1 + ft_strlen(s2);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + size_s1, s2);
	return (res);
}
