/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 21:25:48 by avannest          #+#    #+#             */
/*   Updated: 2013/12/14 22:35:24 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabtree.h"
#include <libft.h>

void				ft_aabtins(t_aabtree **tree, t_aabtree *new)
{
	int				cmp;

	if (!*tree)
		*tree = new;
	else
	{
		cmp = ft_memcmp((*tree)->content, new->content, new->content_size);
		if (cmp > 0 || (cmp == 0 && new->content_size < (*tree)->content_size))
		{
			ft_aabtins(&((*tree)->left), new);
			ft_aabtskew(tree);
		}
		else
		{
			ft_aabtins(&((*tree)->right), new);
			ft_aabtsplit(tree);
		}
	}
}

