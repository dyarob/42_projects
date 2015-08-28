/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:35:05 by avannest          #+#    #+#             */
/*   Updated: 2013/12/08 23:42:47 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "get_next_line.h"

static int			ft_imemchr(char *str, char c, size_t n)
{
	size_t			i;

	i = 0;
	while (str[i] != c && i < n)
		++i;
	return (i);
}

static void			ft_lstdelfront(t_list **alst)
{
	t_list			*todel;

	free((*alst)->content);
	todel = *alst;
	*alst = (*alst)->next;
	free(todel);
}

static int			write_to_line(char **line, t_list **myline, int linelen)
{
	size_t			i;

	if (!(*line = (char *)ft_memalloc(linelen + 1)))
		return (-1);
	while ((*myline))
	{
		linelen -= (*myline)->content_size;
		i = 0;
		while (i < (*myline)->content_size)
		{
			(*line)[linelen + i] = ((char *)((*myline)->content))[i];
			++i;
		}
		ft_lstdelfront(myline);
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*lastbuf = NULL;
	t_list			*buf;
	t_list			*myline;
	int				linelen;
	int				i;

	myline = NULL;
	linelen = (lastbuf ? lastbuf->content_size : 0);
	if (lastbuf)
		ft_lstadd(&myline, lastbuf);
	while (1)
	{
		buf = (t_list *)malloc(sizeof(t_list));
		if (!(buf->content = ft_memalloc(BUFF_SIZE)))
			return (-1);
		buf->content_size = BUFF_SIZE;
		if ((i = read(fd, (char *)buf->content, BUFF_SIZE)) <= 0)
			return i;
		i = ft_imemchr((char *)buf->content, '\n', BUFF_SIZE);
		linelen += i;
		ft_lstadd(&myline, buf);
		ft_putstr((char *)buf->content);
		if (i != BUFF_SIZE)
		{
			if (write_to_line(line, &myline, linelen) < 0)
				return (-1);
			lastbuf = ft_lstnew(ft_strsub((char *)(buf->content), i + 1,
					BUFF_SIZE - (i + 1)),
				BUFF_SIZE - (i + 1));
			return (1);
		}
	}
}




/*
** Static variable devoted to storing the last buffer read when performing the
** readance of a line, in order to memoize the beginning of the next line that
** may appear over the same buffer.
*/
static char		*lastbuf = NULL;

/*
** The following functions read a line from a file.
**   A line is defined as being a serie of characters followed by /n or the
** end of the file. (EOF)
*/
static int		r_get_next_line(int const fd, char **line, unsigned int linelen)
{
	int			i;
	char		*buf;

	buf = (char *)ft_memalloc(BUFF_SIZE + 1);	
	if (!buf)
		return (-1);
	i = read(fd, buf, BUFF_SIZE);
	if (i == -1 || (i == 0 && linelen == 0))
	{
		//if (lastbuf) ft_strdel(&lastbuf);
		ft_strdel(&buf);
		return (i);
	}
	buf[i] = '\0';
	//ft_putstr("contenu de buf ->");
	//ft_putstr(buf);
	//ft_putstr("<-\n");
	i = 0;
	while (buf[i] && buf[i] != '\n')
		++i;
	if (i != BUFF_SIZE)
	{
		//ft_putstr("condition penetree\n");
		*line = (char *)ft_memalloc(linelen + i + 1);
		if (!(*line))
			return (-1);
		(*line)[linelen + i] = '\0';
		//ft_putstr("on va copier le buffer\n");
		if (lastbuf)
		{
			//ft_putstr("XXXX\n");
			ft_strcpy(*line, lastbuf);
			ft_strdel(&lastbuf);
		}
		lastbuf = (char *)ft_memalloc(BUFF_SIZE - i);
		//ft_putstr("BAH ->");
		//ft_putstr(lastbuf);
		//ft_putstr("<-\n");
		ft_strcpy(lastbuf, buf + i + 1);
		//ft_putstr("BAH ->");
		//ft_putstr(lastbuf);
		//ft_putstr("<-\n");
	}
	else if (r_get_next_line(fd, line, linelen + BUFF_SIZE) == -1)
		return (-1);
	while (--i >= 0)
		(*line)[linelen + i] = buf[i];
	ft_strdel(&buf);
	return (1);
}

/*
** This function is the entry point of get_next_line. Its role is to check
** the lastbuf, and initiate the recursive treatment.
**   How it works:
** 1) If lastbuf isn't NULL, checks if there is a \n in it.
**   - If there is, we allocate line, copy the line in it, and return it.
**   - Else we just call the recursive get_next_line function.
*/
int				old_get_next_line(int const fd, char **line)
{
	int			i;
	int			j;
	char		*strtmp;

	i = 0;
	if (lastbuf)
	{
		//ft_putstr("coucou1");
		//ft_putstr("buffer ->");
		//ft_putstr(lastbuf);
		//ft_putstr("<-\n");
		j = 0;
		while (lastbuf[i] != '\n' && lastbuf[i] != '\0')
			++i;
		//ft_putstr("coucou3");
		if (lastbuf[i] != '\0')
		{
		*line = (char *)ft_memalloc(i + 1);
		(*line)[i] = '\0';
		ft_strncpy(*line, lastbuf, i);
			//ft_putstr("coucou4");
			strtmp = ft_strsub(lastbuf, i + 1, ft_strlen(lastbuf));
			free(lastbuf);
			lastbuf = strtmp;
			//ft_putstr("We copied in the buffer ->");
			//ft_putstr(lastbuf);
			//ft_putstr("<-\n");
			//lastbuf += i + 1;
			//free(strtmp);
			return (1);
		}
		//else
			//ft_strdel(&lastbuf);
	}
	//ft_putstr("coucou2");
	i = r_get_next_line(fd, line, i);
	//ft_strdel(&lastbuf);
	return (i);
}

