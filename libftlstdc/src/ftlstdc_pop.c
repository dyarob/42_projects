/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 20:21:12 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 20:50:14 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"

t_lstdc		*ftlstdc_pop(t_lstdc **lst)
{
	t_lstdc	*new;

	new = *lst;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	*lst = (*lst)->next;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		ftlstdc_pop_into(t_lstdc **lst, t_lstdc **dest)
{
	t_lstdc	*new;

	new = *lst;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	*lst = (*lst)->next;
	if (!*dest)
	{
		new->prev = NULL;
		new->next = NULL;
		*dest = new;
	}
	else
		ftlstdc_push(dest, new);
}

