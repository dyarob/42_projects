/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 20:41:28 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:58:37 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>
#include <stdio.h>
#include "ft_aabtree.h"
#include "ft_ls.h"

void				ft_ls_dir(char *dirname, int display_name, t_opt *options)
{
	DIR				*rep;
	struct dirent	*fileread;
	t_aabtree		*tree;

	if (!(rep = opendir(dirname)))
		perror(ft_strjoin("ft_ls: ", dirname));
	else
	{
		if (display_name)
		{
			ft_putstr(dirname);
			ft_putstr(":\n");
		}
		tree = NULL;
		while ((fileread = readdir(rep)))
			if (fileread->d_name[0] != '.' || options->a)
				ft_aabtins(&tree,
					ft_aabtnew(fileread->d_name, fileread->d_namlen));
		closedir(rep);
		ft_aabtprint(tree, 0, options->r);
		ft_aabtdel(&tree);
	}
}

void				ft_ls_dirtree(t_aabtree *tree, t_opt *options)
{
	if (tree)
	{
		if (!options->r)
		{
			ft_ls_dirtree(tree->left, options);
			if (tree->left)
				ft_putchar('\n');
			ft_ls_dir(tree->content, 1, options);
			if (tree->right)
				ft_putchar('\n');
			ft_ls_dirtree(tree->right, options);
		}
		else
		{
			ft_ls_dirtree(tree->right, options);
			if (tree->right)
				ft_putchar('\n');
			ft_ls_dir(tree->content, 1, options);
			if (tree->left)
				ft_putchar('\n');
			ft_ls_dirtree(tree->left, options);
		}
	}
}

void				ft_ls_filetree(t_aabtree *tree, t_opt *options)
{
	if (tree)
		ft_aabtprint(tree, 0, options->r);
}

