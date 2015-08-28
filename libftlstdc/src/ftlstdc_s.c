/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:21:09 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 18:29:52 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"

void	ftlstdc_s(t_lstdc **lst)
{
	t_lstdc		*tmp;

	tmp = (*lst)->prev;
	(*lst)->prev = (*lst)->next;
	(*lst)->next->prev = tmp;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

