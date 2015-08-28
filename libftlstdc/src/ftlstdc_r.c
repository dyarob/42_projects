/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlstdc_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:42:11 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 18:44:12 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlstdc.h"

void	ftlstdc_r(t_lstdc **lst)
{
	*lst = (*lst)->next;
}

void	ftlstdc_rr(t_lstdc **lst)
{
	*lst = (*lst)->prev;
}

