/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:44:27 by avannest          #+#    #+#             */
/*   Updated: 2013/12/01 19:20:49 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** What this function does:
** Create a new string from s without any space at the beginning or the end.
**
** How this function works:
** 1) Skips spaces at the beginning
** 2) If there is nothing left (except \0), returns an empty string.
** 3) Else skips content of the string until the end, for doing the same
** thing, but reversed, in order to not count the spaces at the end of s.
** 4) malloc, then copy using the length it just calculated
** 5) Add of a terminal \0 char, then 'ting! It's all cooked.
*/
char					*ft_strtrim(char const *s)
{
	int					i;
	char				*result;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		++ s;
	if (!*s)
	{
		result = (char *)malloc(1);
		*result = '\0';
		return (result);
	}
	i = 0;
	while (s[i])
		++ i;
	-- i;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		-- i;
	result = (char *)malloc(i + 2);
	if (!result)
		return (NULL);
	result = ft_strncpy(result, s, i + 1);
	*(result + i + 1) = '\0';
	return (result);
}

