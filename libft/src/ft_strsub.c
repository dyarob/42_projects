/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:27:14 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:40:22 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*result;

	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, s + start, len);
	if (result[len])
		result[len] = 0;
	return (result);
}
