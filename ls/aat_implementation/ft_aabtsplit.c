/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 17:38:52 by avannest          #+#    #+#             */
/*   Updated: 2013/12/14 22:36:32 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabtree.h"

void					ft_aabtsplit(t_aabtree **tree)
{
	t_aabtree			*tmp;

	if ((*tree)->right && ((*tree)->right)->right &&
		(*tree)->level == ((*tree)->right)->level &&
		(*tree)->level == (((*tree)->right)->right)->level)
	{
		tmp = (*tree)->right;
		(*tree)->right = (tmp)->left;
		(tmp)->left = *tree;
		++(tmp)->level;
		*tree = tmp;
	}
}

