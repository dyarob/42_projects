/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:23:50 by avannest          #+#    #+#             */
/*   Updated: 2014/04/14 20:36:48 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!ft_strncmp(s1, s2, n))
		return (1);
	return (0);
}
