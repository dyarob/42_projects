/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:03:16 by avannest          #+#    #+#             */
/*   Updated: 2013/11/28 11:15:50 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char					*ft_strdup(const char *s1)
{
	char				*s2;

	s2 = (char *)malloc(ft_strlen(s1));
	if (!s2)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}

