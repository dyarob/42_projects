/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 21:25:09 by avannest          #+#    #+#             */
/*   Updated: 2013/12/06 21:41:46 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>

int					main(void)
{
	DIR				*rep;
	struct dirent	*fileread;		// structure pour les dir(ectory) ent(ity)
									// permet de lire le contenu d'un dossier

	rep = opendir("mondossier");
	if (!rep)
	{
		perror("");
		return (-1);
	}

	while ((fileread = readdir(rep)))	// fileread pointe maintenant sur le pre-
	{									// mier object contenu dans rep.
		ft_putstr("Le fichier lu s'appelle ->");
		ft_putstr(fileread->d_name);	// la structure dirent dispose de champs
										// bien pratiques
		ft_putstr("<-\n");
	}

	if (closedir(rep) == -1)
	{
		perror("");
		return (-1);
	}
	return (0);
}

