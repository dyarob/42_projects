/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:21:18 by avannest          #+#    #+#             */
/*   Updated: 2013/12/14 22:38:43 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int							ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
