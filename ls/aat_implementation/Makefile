# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannest <avannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/29 16:22:43 by avannest          #+#    #+#              #
#    Updated: 2013/12/15 21:59:31 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						ft_ls

CC =						gcc

CFLAGS =					-Wall -Werror -Wextra -g

SRC =						readdir.c ft_ls.c \
							ft_aabtnew.c ft_aabtins.c ft_aabtprint.c \
							ft_aabtskew.c ft_aabtsplit.c \
							ft_aabtdel.c ft_aabtforeach.c

SRC_PATH =					./

SRC_FILES =					$(addprefix $(SRC_PATH),$(SRC))

OBJ =						$(SRC_FILES:.c=.o)

H_PATH =					./

LIB_PATH =					./libft/



all:			libft.a $(NAME)

$(NAME):		$(OBJ)	
	$(CC) -o $(NAME) $^ -I. -L$(LIB_PATH) -lft

# This rule compiles object files one by one.
# $^ = dependancy list (here %.c)
# $@ = rule name (here %.o)
%.o:			%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I. -I$(LIB_PATH)includes/

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

