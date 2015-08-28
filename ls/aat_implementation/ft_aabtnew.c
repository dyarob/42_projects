/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 20:00:59 by avannest          #+#    #+#             */
/*   Updated: 2013/12/14 22:35:34 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabtree.h"
#include <stdlib.h>

t_aabtree				*ft_aabtnew(void *content, size_t content_size)
{
	t_aabtree			*ret;

	if (!(ret = (t_aabtree *)malloc(sizeof(t_aabtree))))
		return (NULL);
	ret->content = content;
	ret->content_size = content_size;
	ret->left = NULL;
	ret->right = NULL;
	ret->level = 1;
	return (ret);
}

