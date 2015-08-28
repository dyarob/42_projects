/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:32:24 by avannest          #+#    #+#             */
/*   Updated: 2013/12/01 19:16:13 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void					*ft_memalloc(size_t size)
{
	void				*res;

	res = malloc(size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}

