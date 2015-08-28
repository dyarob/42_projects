/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngolovin <ngolovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:15:31 by ngolovin          #+#    #+#             */
/*   Updated: 2013/12/19 15:26:28 by ngolovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int nb)
{
	int	root;

	root = 1;
	if (nb <= 0)
		return (0);
	root = 0;
	while (root * root != nb)
	{
		++root;
		if (((root + 1) * (root + 1)) > nb)
		{
			if ((nb - root * root) <= ((root + 1) * (root + 1) - nb))
				return (root);
			else
				return (root + 1);
		}
	}
	return (root);
}
