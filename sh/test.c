/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:42:21 by avannest          #+#    #+#             */
/*   Updated: 2013/12/21 16:00:41 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
//#include <sys/wait.h>

int					main(int ac, char **av)
{
	pid_t			father;

	while (1)
	{
		father = fork();
		if (father == 0)
		{
			execve("/bin/ls", av, NULL);
		}
		else if (father > 0)
		{
			wait();
			printf("# ");
		}
		else
		{
			printf("error\n");
		}
	}
	return (0);
}

