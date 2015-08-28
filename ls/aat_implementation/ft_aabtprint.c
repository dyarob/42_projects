/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 21:09:30 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:14:09 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aabtree.h"
#include <libft.h>

/*
** Only works if the tree contains only nul-terminated strings.
** Should be done with some kind of memprint.
*/
void			ft_aabtprint_one(t_aabtree *tree)
{
	ft_putstr((char *)tree->content);
	ft_putchar('\n');
}

void			ft_aabtprint_levels_one(t_aabtree *tree)
{
	ft_putstr((char *)tree->content);
	ft_putstr(" level=");
	ft_putnbr(tree->level);
	ft_putchar('\n');
}

void			ft_aabtprint(t_aabtree *tree, int display_levels, int reverse)
{
	if (!reverse)
	{
		if (!display_levels)
			ft_aabtforeach(tree, ft_aabtprint_one);
		else
			ft_aabtforeach(tree, ft_aabtprint_levels_one);
	}
	else
	{
		if (!display_levels)
			ft_aabtrforeach(tree, ft_aabtprint_one);
		else
			ft_aabtrforeach(tree, ft_aabtprint_levels_one);
	}
}

