/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 20:55:24 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:25:28 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_aabtree.h"

typedef struct	s_opt
{
	int			R;
	int			a;
	int			l;
	int			r;
	int			t;
}				t_opt;

void			ft_aabtlsins(t_aabtree **tree, t_aabtree *new, t_opt *options);
void			ft_ls_dir(char *dirname, int display_name, t_opt *options);
void			ft_ls_dirtree(t_aabtree *tree, t_opt *options);
void			ft_ls_filetree(t_aabtree *tree, t_opt *options);

#endif /* !FT_LS_H */

