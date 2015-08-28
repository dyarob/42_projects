/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:58:47 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 15:59:43 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t					ft_count_words(char *s, char c)
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

