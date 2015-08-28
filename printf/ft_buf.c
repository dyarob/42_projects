/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:49:58 by avannest          #+#    #+#             */
/*   Updated: 2013/12/20 19:21:46 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"

#include <stdlib.h>
#include <unistd.h>

int					ft_buf_init(t_buf **buf)
{
	if (!(*buf = (t_buf *)malloc(sizeof(t_buf))))
		return (0);
	if (!((*buf)->s = (char *)malloc(BUFF_SIZE)))
		return (0);
	(*buf)->i = 0;
	(*buf)->len = 0;
	return (1);
}

void				ft_buf_inc(t_buf *buf)
{
	if (buf->i < BUFF_SIZE - 1)
		++buf->i;
	else
	{
		write(1, buf->s, BUFF_SIZE);
		buf->len += buf->i;
		buf->i = 0;
	}
}

void				ft_buf_free(t_buf **buf)
{
	free((*buf)->s);
	free(*buf);
	*buf = NULL;
}

