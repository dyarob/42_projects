/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 16:52:07 by avannest          #+#    #+#             */
/*   Updated: 2014/01/12 17:03:41 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>
#include <termios.h>
#include <unistd.h>		/* write */

static void	print_word(int i, t_env *e)
{
	if (e->mod_tab[i] % 2 == 0)
		tputs(tgetstr("us", NULL), 1, ft_iputchar);
	if (e->mod_tab[i] % 3 == 0)
		tputs(tgetstr("mr", NULL), 1, ft_iputchar);
	write(1, e->wrd_tab[i], e->len_tab[i]);
	tputs(tgetstr("me", NULL), 1, ft_iputchar);
	tputs(tgetstr("do", NULL), 1, ft_iputchar);
}

int			display(t_env *e)
{
	int			i;
	int			j;
	int			icol;
	int			column_size;

	tputs(tgetstr("cl", NULL), 1, ft_iputchar);
	i = 0;
	j = 0;
	icol = -1;
	column_size = e->ws->ws_row - 1;
	while (i < e->nb_wrd)
	{
		if (e->mod_tab[i] != 0)
		{
			if (j % column_size == 0)
				++icol;
			tputs(tgoto(tgetstr("cm", NULL), (e->wrd_max_len + 1) * icol,
					j % column_size), 1, ft_iputchar);
			print_word(i, e);
			++j;
		}
		++i;
	}
	return (1);
}

