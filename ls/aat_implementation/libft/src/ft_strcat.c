/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:57:07 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:47:59 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char					*ft_strcat(char *s1, const char *s2)
{
	int					i;

	i = 0;
	while (s1[i])
		++i;
	ft_strcpy(s1 + i, s2);
	return (s1);
}

