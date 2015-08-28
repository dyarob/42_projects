/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 08:30:20 by avannest          #+#    #+#             */
/*   Updated: 2014/01/12 17:58:51 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>
#include <termios.h>
#include <signal.h>		/* signal */
#include <stdlib.h>		/* getenv */
#include <unistd.h>		/* write */

int			ft_iputchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	readchar(char *cbuf)
{
	cbuf[0] = 0;
	cbuf[1] = 0;
	cbuf[2] = 0;
	cbuf[3] = 0;
	while (cbuf[0] == 0)
		read(0, cbuf, 4);
	return (1);
}

int			main(int ac, char **av)
{
	char				buffer[2048];
	struct termios		term;
	char				cbuf[4];
	t_env				*e;

	if (tgetent(buffer, getenv("TERM")) <= 0)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ICANON;
	term.c_lflag &= ECHO;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, ft_iputchar);
	tputs(tgetstr("vi", NULL), 1, ft_iputchar);
	if (env_init(&e, &term,
			ac - 1, av + 1) <= 0)
		return (-1);
	signal_handlers_init(e);
	display(e);
	while (1)
	{
		signal(SIGWINCH, &fs_resize);
		readchar(cbuf);
		if (process_key(e, cbuf))
			display(e);
	}
}

