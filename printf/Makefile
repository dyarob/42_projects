# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannest <avannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/29 16:22:43 by avannest          #+#    #+#              #
#    Updated: 2013/12/20 16:56:05 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						libftprintf.a

CC =						llvm-gcc

CFLAGS =					-Wall -Werror -Wextra

SRC =						ft_printf.c ft_buf.c ft_putnbrb.c

SRC_PATH =					./

SRC_FILES =					$(addprefix $(SRC_PATH),$(SRC))

OBJ =						$(SRC_FILES:.c=.o)

H_PATH =					./





all:			$(NAME)

$(NAME):		$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# This rule compiles object files one by one.
# $^ = dependancy list (here %.c)
# $@ = rule name (here %.o)
%.o:			%.c
	$(CC) -c $^ -o $@ $(CFLAGS) -I $(H_PATH) 

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:				fclean all

