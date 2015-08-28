/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:44:47 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 18:57:04 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"
#include <stdlib.h>

t_lstdc		*ftlstdc_new(void *cont, t_uint cont_size)
{
	t_lstdc	*ret;

	if (!(ret = (t_lstdc *)malloc(sizeof(t_lstdc))))
		return (NULL);
	ret->cont = cont;
	ret->cont_size = cont_size;
	ret->prev = ret;
	ret->next = ret;
	return (ret);
}

