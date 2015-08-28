/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:26:33 by avannest          #+#    #+#             */
/*   Updated: 2013/12/18 20:58:45 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlst.h"

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}

