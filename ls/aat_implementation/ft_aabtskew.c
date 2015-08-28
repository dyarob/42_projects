/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtskew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:53:02 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 15:39:54 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabtree.h"

void					ft_aabtskew(t_aabtree **tree)
{
	t_aabtree			*tmp;

	if ((*tree)->level == ((*tree)->left)->level)
	{
		tmp = (*tree)->left;
		(*tree)->left = tmp->right;
		tmp->right = *tree;
		*tree = tmp;
		ft_aabtsplit(tree);
	}
}

