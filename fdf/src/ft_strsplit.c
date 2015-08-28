/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:58:47 by avannest          #+#    #+#             */
/*   Updated: 2013/12/01 19:19:13 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t			count_words(char *s, char c)
{
	size_t				nb_words;

	while (*s && *s == c)
		++ s;
	nb_words = (*s ? 1 : 0);
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			++ nb_words;
		++ s;
	}
	return (nb_words);
}

char					**ft_strsplit(char const *s, char c)
{
	size_t				nb_words;
	char				*wrd_begin;
	char				**result;

	nb_words = count_words((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	wrd_begin = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (wrd_begin != s)
				*(result ++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
			wrd_begin = (char *)s + 1;
		}
		++ s;
	}
	if (wrd_begin != s)
		*(result ++) = ft_strsub(wrd_begin, 0, s - wrd_begin);
	*result = NULL;
	return (result - nb_words);
}

