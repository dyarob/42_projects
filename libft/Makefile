# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannest <avannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/29 16:22:43 by avannest          #+#    #+#              #
#    Updated: 2013/12/18 19:50:13 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						libft.a

CC =						gcc

CFLAGS =					-Wall -Werror -Wextra

SRC =						ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
							ft_memmove.c ft_memchr.c ft_memcmp.c \
							\
							ft_strcat.c ft_strncat.c ft_strchr.c \
							ft_strrchr.c ft_strcmp.c ft_strncmp.c \
							ft_strcpy.c ft_strncpy.c ft_strdup.c \
							ft_strlcat.c ft_strlen.c ft_strstr.c \
							ft_strnstr.c \
							\
							ft_isalpha.c ft_isdigit.c ft_isalnum.c \
							ft_isascii.c ft_isprint.c \
							\
							ft_toupper.c ft_tolower.c \
							\
							ft_memalloc.c ft_memdel.c \
							ft_strnew.c ft_strdel.c \
							\
							ft_strclr.c ft_striter.c ft_striteri.c \
							ft_strmap.c ft_strmapi.c ft_strequ.c \
							ft_strnequ.c ft_strsplit.c ft_strsub.c \
							ft_strjoin.c ft_strtrim.c \
							\
							ft_atoi.c ft_itoa.c \
							ft_putendl.c ft_putendl_fd.c \
							ft_putchar.c ft_putchar_fd.c \
							ft_putstr.c ft_putstr_fd.c \
							ft_putnbr.c ft_putnbr_fd.c

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
	$(CC) -c $^ -o $@ $(CFLAGS) -I $(H_PATH) 

clean:
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean:			clean
	rm -f $(NAME)

re:				fclean all

