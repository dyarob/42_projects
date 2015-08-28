/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 19:06:33 by avannest          #+#    #+#             */
/*   Updated: 2013/12/14 22:35:15 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabtree.h"
#include <stdlib.h>

void					ft_aabtdel(t_aabtree **tree)
{
	if ((*tree)->left)
		ft_aabtdel((&(*tree)->left));
	if ((*tree)->right)
		ft_aabtdel(&((*tree)->right));
	free(*tree);
	*tree = NULL;
}

