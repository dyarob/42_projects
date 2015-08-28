/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:53:53 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 18:59:15 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"
#include <stdlib.h>

void		ftlstdc_free(t_lstdc **lst)
{
	(*lst)->prev->next = NULL;
	while ((*lst)->next)
	{
		free((*lst)->cont);
		*lst = (*lst)->next;
		free((*lst)->prev);
	}
	free((*lst)->cont);
	free(*lst);
	*lst = NULL;
}

