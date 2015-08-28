/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercept_sizeterm_mod_signal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngolovin <ngolovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 06:08:39 by ngolovin          #+#    #+#             */
/*   Updated: 2014/01/06 04:04:03 by ngolovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	test_function(void)
{
	sleep(10);
//	printf("meanwhile in russia...\n");
}

void	ft_mysig(int sigint)
{
	struct winsize	mywin;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &mywin);
	printf("lignes : %d\n", mywin.ws_row);
	printf("colonnes : %d\n", mywin.ws_col);
}

int main (int argc, char **argv)
{
	while (1)
	{
		signal(SIGWINCH, &ft_mysig);
		test_function();
	}
	return (0);
}

