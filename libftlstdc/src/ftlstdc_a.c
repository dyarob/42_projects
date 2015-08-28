/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:31:33 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 20:12:29 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"

int		ftlstdc_a(t_lstdc **lst, void *cont, t_uint cont_size)
{
	t_lstdc		*new;

	if (!(new = ftlstdc_new(cont, cont_size)))
		return (0);
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = (*lst)->prev;
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	return (1);
}

