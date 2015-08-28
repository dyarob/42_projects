/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:52:02 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 18:59:11 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"
#include <unistd.h>

void	ftlstdc_print(t_lstdc *lst)
{
	t_lstdc		*head;

	write(1, lst->cont, lst->cont_size);
	head = lst;
	lst = lst->next;
	while (lst != head)
	{
		write(1, lst->cont, lst->cont_size);
		lst = lst->next;
	}
}

