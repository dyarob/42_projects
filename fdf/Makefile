# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannest <avannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/29 16:22:43 by avannest          #+#    #+#              #
#    Updated: 2013/12/22 20:04:30 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						fdf

CC =						gcc

CFLAGS =					-Wall -Werror -Wextra -g

SRC =						main.c \
							mlx_line_put.c \
							mlx_map_put.c \
							ft_coords.c ft_map.c \
							ft_projection.c \
							get_next_line.c
#							ft_sqrt.c \

SRC_PATH =					./src/

SRC_FILES =					$(addprefix $(SRC_PATH),$(SRC))

OBJ =						$(SRC_FILES:.c=.o)

H_PATH =					./includes/

LIB_PATH =					./libft/



all:			libft.a $(NAME)

$(NAME):		$(OBJ)	
	$(CC) -o $(NAME) $^ -I$(H_PATH) -L$(LIB_PATH) -lft -L/usr/X11/lib -lmlx -lXext -lX11

# This rule compiles object files one by one.
# $^ = dependancy list (here %.c)
# $@ = rule name (here %.o)
%.o:			%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I$(H_PATH) -I$(LIB_PATH)includes/

libft.a:
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean:
	make -C $(LIB_PATH) fclean
	rm -f $(OBJ)
	rm -f libft.h.gch
	rm -f $(NAME)

re:				fclean all

