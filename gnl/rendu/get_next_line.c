/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:35:05 by avannest          #+#    #+#             */
/*   Updated: 2013/12/08 19:30:40 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "get_next_line.h"

static int		ft_istrchr(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}

static void		ft_cpyndel(char **line, char **strtmp)
{
	ft_strcpy(*line, *strtmp);
	ft_strdel(strtmp);
}

/*
** The following functions reads a line from a file.
**   A line is defined as being a serie of characters followed by /n or the
** end of the file. (EOF)
*/
static int		r_get_next_line(int const fd, char **line, unsigned int linelen,
	char **lastbuf)
{
	int			i;
	char		*buf;

	if (!(buf = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	i = read(fd, buf, BUFF_SIZE);
	if (i != -1 && !(i == 0 && linelen == 0))
	{
		i = ft_istrchr(buf);
		if (i != BUFF_SIZE)
		{
			if (!(*line = (char *)ft_memalloc(linelen + i + 1)))
				return (-1);
			if (*lastbuf)
				ft_cpyndel(line, lastbuf);
			*lastbuf = ft_strsub(buf, i + 1, BUFF_SIZE - i);
		}
		else if (r_get_next_line(fd, line, linelen + BUFF_SIZE, lastbuf) == -1)
			return (-1);
		while (--i >= 0)
			(*line)[linelen + i] = buf[i];
		i = 1;
	}
	ft_strdel(&buf);
	return (i);
}

/*
** This function is the entry point of get_next_line. Its role is to check
** the lastbuf, and initiate the recursive treatment.
*/
int				get_next_line(int const fd, char **line)
{
	int			i;
	char		*strtmp;
	static char	*lastbuf = NULL;

	i = 0;
	if (lastbuf)
	{
		while (lastbuf[i] != '\n' && lastbuf[i] != '\0')
			++i;
		if (lastbuf[i] != '\0')
		{
			if (!(*line = (char *)ft_memalloc(i + 1)))
				return (-1);
			ft_strncpy(*line, lastbuf, i);
			strtmp = ft_strsub(lastbuf, i + 1, ft_strlen(lastbuf));
			free(lastbuf);
			lastbuf = strtmp;
			return (1);
		}
	}
	i = r_get_next_line(fd, line, i, &lastbuf);
	return (i);
}

