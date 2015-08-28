/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 21:25:09 by avannest          #+#    #+#             */
/*   Updated: 2013/12/07 20:17:20 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

int					main(void)
{
	DIR				*rep;
	struct dirent	*fileread;		// structure pour les dir(ectory) ent(ity)
									// permet de lire le contenu d'un dossier

	t_list			**dirlist;		// une liste pour stocker les dirent*
	t_list			*coucou;

	dirlist = (t_list**)malloc(sizeof(t_list*));
	*dirlist = NULL;
	rep = opendir("/nfs/sgoinfre/goinfre");
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
		coucou = ft_lstnew(fileread->d_name, ft_strlen(fileread->d_name) + 1);
		//ft_lstadd(dirlist, coucou);
		coucou->next = *dirlist;
		ft_putstr("<-\n");
		*dirlist = coucou;
		//ft_putstr("Le maillon a bien ete ajoute.\n");
	}

	if (closedir(rep) == -1)
	{
		perror("");
		return (-1);
	}
	return (0);
}

