/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:00:19 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:32:31 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i] || i == n - 1)
			return (0);
		++i;
	}
	return (s1[i] - s2[i]);
}
