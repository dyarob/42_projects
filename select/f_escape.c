/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_escape.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 05:09:14 by avannest          #+#    #+#             */
/*   Updated: 2014/01/06 05:50:34 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <termcap.h>

void	f_escape(t_env *e)
{
	tputs(tgetstr("te", NULL), 1, ft_iputchar);
	e->term->c_lflag &= ICANON;
	e->term->c_lflag &= ECHO;
	tcsetattr(0, 0, e->term);
	env_free(&e);
	exit(0);
}

