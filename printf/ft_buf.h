/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:09:37 by avannest          #+#    #+#             */
/*   Updated: 2013/12/20 19:11:37 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_buf_H
# define ft_buf_H

# define BUFF_SIZE 128

typedef struct		s_buf
{
	char			*s;
	int				i;
	int				len;
}					t_buf;

/*
** Dealing with memory
*/
int					ft_buf_init(t_buf **buf);
void				ft_buf_free(t_buf **buf);

/*
** Operations
*/
void				ft_buf_inc(t_buf *buf);

/*
** Filling utilitaries
*/
void				ft_putchar_b(char c, t_buf *b);
void				ft_putstr_b(char *s, t_buf *b);
void				ft_write_b(t_buf *b, char *s, int n);
void				ft_putnbr_b(int n, t_buf *b);
void				ft_putuint_b(unsigned int n, t_buf *b);

#endif /* !FT_BUF_H */

