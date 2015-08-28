/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:24:54 by avannest          #+#    #+#             */
/*   Updated: 2013/12/18 20:58:58 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlst.h"
#include <stdlib.h>

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

