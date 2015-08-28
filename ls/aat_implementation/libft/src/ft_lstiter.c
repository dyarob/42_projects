/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:30:44 by avannest          #+#    #+#             */
/*   Updated: 2013/11/30 15:59:21 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst->next)
		ft_lstiter(lst->next, f);
	f(lst);
}

