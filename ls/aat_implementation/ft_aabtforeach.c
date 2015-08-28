/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtforeach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 16:02:20 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:26:32 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabtree.h"

void				ft_aabtforeach(t_aabtree *tree, void (*f)(t_aabtree *tree))
{
	if (tree->left)
		ft_aabtforeach(tree->left, f);
	f(tree);
	if (tree->right)
		ft_aabtforeach(tree->right, f);
}

void				ft_aabtrforeach(t_aabtree *tree, void (*f)(t_aabtree *tree))
{
	if (tree->right)
		ft_aabtrforeach(tree->right, f);
	f(tree);
	if (tree->left)
		ft_aabtrforeach(tree->left, f);
}
