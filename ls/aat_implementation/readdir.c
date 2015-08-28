/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 21:25:09 by avannest          #+#    #+#             */
/*   Updated: 2013/12/15 21:36:27 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "ft_aabtree.h"
#include "ft_ls.h"

static int			init_opt(t_opt **options)
{
	if (!(*options = (t_opt *)malloc(sizeof(t_opt))))
	{
		perror("ft_ls: ");
		return (-1);
	}
	(*options)->R = 0;
	(*options)->a = 0;
	(*options)->l = 0;
	(*options)->r = 0;
	(*options)->t = 0;
	return (0);
}

static int			get_one_opt(t_opt *options, char o)
{
	if (o == 'R')
		options->R = 1;
	else if (o == 'a')
		options->a = 1;
	else if (o == 'l')
		options->l = 1;
	else if (o == 'r')
		options->r = 1;
	else if (o == 't')
		options->t = 1;
	else
		return (0);
	return (1);
}

static int			get_opt(t_opt *options, int ac, char **av)
{
	int				i;
	int				j;

	i = 1;
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (!get_one_opt(options, av[i][j]))
			{
				ft_putstr("ft_ls: illegal option -- ");
				ft_putchar(av[i][j]);
				ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
				return (-1);
			}
			++j;
		}
		++i;
	}
	return (i);
}

static void			fill_arg_trees(t_aabtree **filetree, t_aabtree **dirtree,
	int ac, char **av)
{
	struct stat		buf;
	int				i;

	i = 0;
	while (i < ac)
	{
		if (!stat(av[i], &buf))
		{
			if (buf.st_mode & S_IFDIR)
				ft_aabtins(dirtree,
					ft_aabtnew(av[i], ft_strlen(av[i]) + 1));
			else
				ft_aabtins(filetree,
					ft_aabtnew(av[i], ft_strlen(av[i]) + 1));
		}
		else
			perror(ft_strjoin("ft_ls: ", av[i]));
		++i;
	}
}

int					main(int ac, char **av)
{
	int				i;
	t_opt			*options;
	t_aabtree		*filetree;
	t_aabtree		*dirtree;

	filetree = NULL;
	dirtree = NULL;
	if (init_opt(&options) == -1)
		return (-1);
	if ((i = get_opt(options, ac, av)) == ac)
	{
		ft_ls_dir(".", 0, options);
		return (0);
	}
	else if (i == -1)
		return (-1);
	fill_arg_trees(&filetree, &dirtree, ac - i, av + i);
	ft_ls_filetree(filetree, options);
	if (filetree && dirtree)
		ft_putchar('\n');
	ft_ls_dirtree(dirtree, options);
	return (0);
}

