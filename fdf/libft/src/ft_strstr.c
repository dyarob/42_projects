/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:14:59 by avannest          #+#    #+#             */
/*   Updated: 2013/11/30 19:46:13 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strstr(const char *s1, const char *s2)
{
	if (!*s2)
		return ((char *)s1);
	if (!*s1)
		return (NULL);
	if (*s1 == *s2 && !ft_strncmp(s1, s2, ft_strlen(s2)))
		return ((char *)s1);
	return (ft_strstr(++ s1, s2));
}

