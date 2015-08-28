/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:40:25 by avannest          #+#    #+#             */
/*   Updated: 2013/12/22 22:56:14 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_coords.h"
#include "ft_draw.h"
#include "get_next_line.h"
#include "ft_map.h"
#include <libft.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

static int		ft_get_dimensions(char *filename, int *lines, int *columns)
{
	int			c;
	char		*line;
	int			fd;

	*columns = 0;
	*lines = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	while ((c = get_next_line(fd, &line)) > 0)
	{
		if ((c = ft_count_words(line, ' ')) > *columns)
			*columns = c;
		++*lines;
	}
	close(fd);
	return (c);
}

static int		ft_get_map(char *filename, t_map *map)
{
	int			l;
	int			c;
	char		*line;
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	l = 0;
	while ((c = get_next_line(fd, &line)) > 0)
	{
		c = 0;
		while (c < map->columns)
		{
			map->tab[l][c] = ft_atois(&line);
			++c;
		}
		++l;
	}
	close(fd);
	return (c);
}

static int		ft_create_map(char *filename, t_map **map)
{
	int			lines;
	int			columns;

	if (ft_get_dimensions(filename, &lines, &columns) == -1)
		return (-1);
	if (!(*map = ft_map_new(lines, columns)))
		return (-1);
	if (ft_get_map(filename, *map) == -1)
		return (-1);
	return (1);
}

static int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit (1);
	return (0);
}

int				main(int ac, char **av)
{
	t_map		*map;
	t_env		e;

	if (ac < 2)
	{
		write(1, "usage : ./fdf file1\n", 20);
		return (-1);
	}
	if (ft_create_map(av[1], &map) == -1)
		return (-1);
	if (!(e.mlx = mlx_init()) ||
		!(e.win = mlx_new_window(e.mlx, 2000, 1000, "fdf")))
		return (-1);
	mlx_map_put(e.mlx, e.win, map);
	ft_map_del(&map);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}

