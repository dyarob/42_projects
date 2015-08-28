/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:54:04 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 18:11:01 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct	s_map
{
	int			**tab;
	int			lines;
	int			columns;
}				t_map;

t_map			*ft_map_new(int lines, int columns);
void			ft_map_del(t_map **map);
void			ft_debug_print(t_map *map);

#endif /* !FT_MAP_H */

