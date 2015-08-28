/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 17:20:22 by avannest          #+#    #+#             */
/*   Updated: 2013/12/09 21:53:31 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_aabtree.h"

int					main(void)
{
	t_aabtree		*mytree;

	mytree = ft_aabtnew(ft_strdup("coucou"), sizeof(char *));
	ft_aabtins(&mytree, ft_aabtnew(ft_strdup("coucou2"), sizeof(char *)));
	ft_aabtins(&mytree, ft_aabtnew(ft_strdup("nico2"), sizeof(char *)));
	ft_aabtins(&mytree, ft_aabtnew(ft_strdup("nico"), sizeof(char *)));
	ft_aabtprint(mytree);
	return (0);
}

