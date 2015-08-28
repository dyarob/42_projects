/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 06:44:54 by avannest          #+#    #+#             */
/*   Updated: 2014/01/12 07:03:37 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>

static t_env	*e;

void	signal_handlers_init(t_env *env)
{
	e = env;
}

void	fs_resize(int sigint)
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, e->ws);
	display(e);
}

