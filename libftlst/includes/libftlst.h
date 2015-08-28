/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftlst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:56:27 by avannest          #+#    #+#             */
/*   Updated: 2013/12/26 20:16:36 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTLST_H
# define LIBFTLST_H

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

/*
** lstadd and lst_push_front are exactly the same function.
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ftlst_push_front(t_list **lst, t_list *new);
void				ftlst_push_back(t_list *lst, t_list *new);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif /* !LIBFTLST_H */

