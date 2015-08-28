/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 03:14:16 by avannest          #+#    #+#             */
/*   Updated: 2014/01/12 18:23:53 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"
#include <stdlib.h> /* malloc */

int		process_key(t_env *e, char *cbuf)
{
	int		i;

	i = 0;
	while (i < NB_KEY)
	{
		if (!ft_memcmp(e->key_tab[i].key, cbuf, 4))
		{
			e->key_tab[i].f(e);
			return (1);
		}
		++i;
	}
	return (0);
}

int		key_tab_init(t_key **key_tab)
{
	if (!(*key_tab = (t_key *)malloc(sizeof(t_key) * NB_KEY)))
		return (0);
	(*key_tab)[0] = (t_key){ K_RETURN, &f_return };
	(*key_tab)[1] = (t_key){ K_DELETE, &f_delete };
	(*key_tab)[2] = (t_key){ K_BACKSPACE, &f_delete };
	(*key_tab)[3] = (t_key){ K_ESCAPE, &f_escape };
	(*key_tab)[4] = (t_key){ K_SPACE, &f_select };
	(*key_tab)[5] = (t_key){ K_ARROW_UP, &f_move_up };
	(*key_tab)[6] = (t_key){ K_ARROW_DOWN, &f_move_down };
	(*key_tab)[7] = (t_key){ K_ARROW_RIGHT, &f_move_right };
	(*key_tab)[8] = (t_key){ K_ARROW_LEFT, &f_move_left };
	return (1);
}

void	key_tab_free(t_key **key_tab)
{
	free(*key_tab);
	*key_tab = NULL;
}

