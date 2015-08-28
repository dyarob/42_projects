/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 21:39:42 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 22:58:16 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_H
# define FT_DRAW_H

# include "ft_coords.h"
# include "ft_map.h"
# include <mlx.h>

# define SIN_A 0.8
# define SIN_B 0.5
# define P_STEP 80
# define X_MARGIN 50
# define Y_MARGIN 300

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

/*
** Elementary drawing
*/
void				mlx_line_put(void *mlx_ptr, void *win_ptr,
	t_coord2 p1, t_coord2 p2, int color);

/*
** 3D projection
*/
t_coord2			ft_project(t_coord3 in);
void				mlx_map_put(void *mlx, void *win, t_map *map);

#endif /* !FT_DRAW_H */

