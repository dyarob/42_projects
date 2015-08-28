/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftlstdc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:13:45 by avannest          #+#    #+#             */
/*   Updated: 2013/12/27 20:34:14 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTLSTDC_H
# define LIBFTLSTDC_H

# ifndef NULL
#  define NULL 0
# endif

typedef	unsigned int	t_uint;

typedef struct			s_lstdc
{
	void				*cont;
	t_uint				cont_size;
	struct s_lstdc		*prev;
	struct s_lstdc		*next;
}						t_lstdc;

t_lstdc		*ftlstdc_new(void *cont, t_uint cont_size);
void		ftlstdc_free(t_lstdc **lst);

void		ftlstdc_s(t_lstdc **lst);
int			ftlstdc_a(t_lstdc **lst, void *cont, t_uint cont_size);
void		ftlstdc_push(t_lstdc **lst, t_lstdc *new);
t_lstdc		*ftlstdc_pop(t_lstdc **lst);
void		ftlstdc_pop_into(t_lstdc **lst, t_lstdc **dest);
void		ftlstdc_r(t_lstdc **lst);
void		ftlstdc_rr(t_lstdc **lst);

void		ftlstdc_print(t_lstdc *lst);

#endif /* !LIBFTLSTDC_H */

