/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:11:35 by amerle            #+#    #+#             */
/*   Updated: 2013/12/05 15:30:20 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <string.h>
#include <signal.h>

#define RED			"31"
#define GREEN		"32"
#define ORANGE		"33"
#define NO			"0"
#define COLOR(X) 	"\033["X"m"

int		g_tests;
int		g_success;

void	sig_alarm(int t)
{
	(void)t;
	printf(COLOR(RED)"Timeout\n"COLOR(NO));
	exit(0);
}

void	ft_test_file(char *file, char multiples, char *diff)
{
	char		buff2[2048];
	pid_t		id;
	size_t		count;
	int			stat;
	char		buffer[2048];
	int			fd;
	ssize_t		ret;

	printf(COLOR(GREEN)"Test starting : %s\n"COLOR(NO), file);

	id = fork();
	if (id == 0)
	{
		stat = snprintf(buff2, sizeof(buff2) - 1, "./test.prog %s > sortie", file);
		buff2[stat] = 0;
		system(buff2);
		_exit(0);
	}
	else if (id == -1)
		printf(COLOR(RED)"Can't create fork()"COLOR(NO));
	else
	{
		waitpid(id, &stat, 0);
		stat = snprintf(buff2, sizeof(buff2) - 1, "diff %s sortie > test.diff", (!multiples) ? file : diff);
		buff2[stat] = 0;
		system(buff2);
	}
	count = 0;
	fd = open("test.diff", O_RDONLY);
	while ((ret = read(fd, buffer, 2047)) > 0)
	{
		if (!count)
			printf("Diff file : \n");
		++count;

		buffer[ret] = 0;
		printf(COLOR(ORANGE)"%s"COLOR(NO), buffer);
	}
	if (count)
		printf(COLOR(RED)"Failed\n\n"COLOR(NO));
	else
		printf(COLOR(GREEN)"Success\n\n"COLOR(NO));
}

static void	ft_generate_file(char *file, size_t max, char *str, size_t strlen, char n)
{
	size_t	wc;
	int		fd;

	printf(COLOR(NO)"Waiting for create file (%s) ...\n", file);
	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(1);
	wc = 0;
	while (wc < max)
	{
		wc += write(fd, str, strlen);
	}
	if (n)
		write(fd, "\n", 1);
	close(fd);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			fd2;
	int			cur_fd;
	int			ret;
	char		*buf;
	
	char		str[] = ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
	char		str2[] = ";;;;;;;;;\n;;;;;;\n;;;;;;;;;;;;\n;;;;;\n;;;;;;;;;;;\n;;;;;;;;\n;;;;;\n";

	signal(SIGALRM, sig_alarm);
	if (argc == 1)
	{
		ft_test_file("main.c", 0, 0);
		ft_test_file("Makefile", 0, 0);
		ft_generate_file("bigfile.file", 10000000, str, sizeof(str) - 1, 1);
		ft_test_file("bigfile.file", 0, 0);
		ft_generate_file("mullines.file", 10000000, str2, sizeof(str2) - 1, 0);
		ft_test_file("mullines.file", 0, 0);
		ft_generate_file("empty.file", 0, 0, 0, 0);
		ft_test_file("empty.file", 0, 0);
		system("./maker main.c Makefile > diff_fds.file_save");
		ft_test_file("main.c Makefile", 1, "diff_fds.file_save");
		system("rm *.file sortie test.diff");
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &buf) == 1)
			printf("%s\n", buf);
		if (fd != -1)
			close(fd);
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		cur_fd = fd;
		ret = 2;
		while (ret)
		{
			if (get_next_line(cur_fd, &buf) == 1)
			{
				printf("%s\n", buf);
			}
			else
			{
				--ret;
				cur_fd = (cur_fd == fd) ? fd2 : fd;
			}
			if (ret == 2)
				cur_fd = (cur_fd == fd) ? fd2 : fd;
		}
		close(fd);
		close(fd2);
	}
	return (0);
}
