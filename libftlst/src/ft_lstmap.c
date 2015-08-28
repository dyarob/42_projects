/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:32:47 by avannest          #+#    #+#             */
/*   Updated: 2013/12/18 20:59:24 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlst.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*newlst;
	t_list			*tmp;

	tmp = f(lst);
	newlst = tmp;
	while (lst->next)
	{
		tmp->next = f(lst->next);
		lst = lst->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (newlst);
}

