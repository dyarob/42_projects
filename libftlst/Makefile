# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannest <avannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/29 16:22:43 by avannest          #+#    #+#              #
#    Updated: 2013/12/26 20:20:38 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						libftlst.a

CC =						gcc

CFLAGS =					-Wall -Werror -Wextra

SRC =						ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
							ft_lstadd.c ft_lstiter.c ft_lstmap.c \
							ftlst_push.c

SRC_PATH =					./src/

SRC_FILES =					$(addprefix $(SRC_PATH),$(SRC))

OBJ =						$(SRC_FILES:.c=.o)

H_PATH =					./includes/





all:			$(NAME)

$(NAME):		$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# This rule compiles object files one by one.
# $^ = dependancy list (here %.c)
# $@ = rule name (here %.o)
%.o:			%.c
	$(CC) -c $^ -o $@ $(CFLAGS) -I$(H_PATH) 

clean:
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean:			clean
	rm -f $(NAME)

re:				fclean all

