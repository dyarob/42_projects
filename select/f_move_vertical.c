/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_move_vertical.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 05:09:14 by avannest          #+#    #+#             */
/*   Updated: 2014/01/12 03:59:16 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	move_up(t_env *e)
{
	if (e->cursor > 0)
		--e->cursor;
	else
		e->cursor = e->nb_wrd - 1;
}

void		f_move_up(t_env *e)
{
	e->mod_tab[e->cursor] /= 2;
	move_up(e);
	while (e->mod_tab[e->cursor] == 0)
		move_up(e);
	e->mod_tab[e->cursor] *= 2;
}

static void	move_down(t_env *e)
{
	if (e->cursor <= e->nb_wrd)
		++e->cursor;
	else
		e->cursor = 0;
}

void		f_move_down(t_env *e)
{
	int		tmp;

	e->mod_tab[e->cursor] /= 2;
	tmp = e->cursor;
	move_down(e);
	while (e->mod_tab[e->cursor] == 0)
	{
		if (tmp == e->cursor)
		{
			f_escape(e);
		}
		move_down(e);
	}
	e->mod_tab[e->cursor] *= 2;
}

