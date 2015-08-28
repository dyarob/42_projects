/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 21:18:11 by avannest          #+#    #+#             */
/*   Updated: 2013/12/21 19:00:02 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COORDS_H
# define FT_COORDS_H

typedef struct		s_coord2
{
	int				x;
	int				y;
}					t_coord2;

typedef struct		s_coord3
{
	int				x;
	int				y;
	int				z;
}					t_coord3;

t_coord2			ft_coord2_new(int x, int y);
t_coord3			ft_coord3_new(int x, int y, int z);

t_coord2			ft_coord3to2(t_coord3 p);

#endif /* !FT_COORDS_H */

