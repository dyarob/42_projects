/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 06:33:50 by avannest          #+#    #+#             */
/*   Updated: 2014/01/12 18:23:51 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"		/* ft_strlen */
#include <stdlib.h>		/* malloc free */
#include <sys/ioctl.h>	/* winsize */
#include <unistd.h>		/* STDOUT_FILENO */

static int	calc_wrd_lens(int *len_tab, int nb_wrd, char **wrd_tab,
	int *mod_tab)
{
	int		i;
	int		max;

	len_tab[0] = ft_strlen(wrd_tab[0]);
	max = len_tab[0];
	mod_tab[0] = 2;
	i = 1;
	while (i < nb_wrd)
	{
		len_tab[i] = ft_strlen(wrd_tab[i]);
		mod_tab[i] = 1;
		if (len_tab[i] > max)
			max = len_tab[i];
		++i;
	}
	return (max);
}

int			env_init(t_env **e, struct termios *term, int nb_wrd,
	char **wrd_tab)
{
	if (!(*e = (t_env *)malloc(sizeof(t_env)))
		|| !((*e)->len_tab = (int *)malloc(sizeof(int) * nb_wrd))
		|| !((*e)->mod_tab = (int *)malloc(sizeof(int) * nb_wrd))
		|| !((*e)->key_tab = (t_key *)malloc(sizeof(t_key) * NB_KEY))
		|| !((*e)->ws = (struct winsize *)malloc(sizeof(struct winsize)))
		|| !key_tab_init(&(*e)->key_tab))
		return (0);
	(*e)->nb_wrd = nb_wrd;
	(*e)->wrd_tab = wrd_tab;
	(*e)->wrd_max_len = calc_wrd_lens((*e)->len_tab, (*e)->nb_wrd,
		(*e)->wrd_tab, (*e)->mod_tab);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, (*e)->ws);
	(*e)->term = term;
	return (1);
}

void		env_free(t_env **e)
{
	free((*e)->len_tab);
	free((*e)->mod_tab);
	key_tab_free(&(*e)->key_tab);
	free(*e);
	*e = NULL;
}

