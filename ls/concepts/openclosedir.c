/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openclosedir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:10:45 by avannest          #+#    #+#             */
/*   Updated: 2013/12/06 21:24:18 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>

int					main(void)
{
	DIR				*rep;

	rep = opendir("norights");
	if (!rep)
	{
		perror("bouh!");
		return (-1);
	}
	ft_putstr("Le dossier a ete ouvert avec succes.\n");
	if (closedir(rep) == -1)
	{
		perror("bouh!");
		return (-1);
	}
	ft_putstr("Le dossier a ete ferme avec succes.\n");
	return (0);
}

