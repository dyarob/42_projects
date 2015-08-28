/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlst_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:07:11 by avannest          #+#    #+#             */
/*   Updated: 2013/12/26 20:23:55 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlst.h"

void			ftlst_push_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void			ftlst_push_back(t_list *lst, t_list *new)
{
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

