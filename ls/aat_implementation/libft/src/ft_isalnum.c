/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:26:31 by avannest          #+#    #+#             */
/*   Updated: 2013/12/14 22:38:23 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
