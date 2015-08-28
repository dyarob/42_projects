/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:31:33 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 20:20:17 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"

void	ftlstdc_push(t_lstdc **lst, t_lstdc *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = (*lst)->prev;
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
}

