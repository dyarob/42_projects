/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aabtree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 12:41:06 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:59:46 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AABTREE_H
# define FT_AABTREE_H

# include <string.h>

typedef struct			s_aabtree
{
	void				*content;
	size_t				content_size;
	struct s_aabtree	*left;
	struct s_aabtree	*right;
	size_t				level;
}						t_aabtree;

/*
** Basic operations
*/
t_aabtree				*ft_aabtnew(void *content, size_t content_size);
void					ft_aabtins(t_aabtree **tree, t_aabtree *new);
void					ft_aabtdel(t_aabtree **tree);

/*
** Balancing the tree
*/
void					ft_aabtskew(t_aabtree **tree);
void					ft_aabtsplit(t_aabtree **tree);

/*
** Moving around
*/
void					ft_aabtforeach(t_aabtree *tree,
	void (*f)(t_aabtree *tree));
void					ft_aabtrforeach(t_aabtree *tree,
	void (*f)(t_aabtree *tree));

/*
** Printing
*/
void					ft_aabtprint(t_aabtree *tree, int display_levels,
	int reverse);
void					ft_aabtprint_one(t_aabtree *tree);
void					ft_aabtprint_levels_one(t_aabtree *tree);

#endif /* !FT_AABTREE_H */

