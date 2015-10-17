# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avannest <avannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/15 14:00:11 by avannest          #+#    #+#              #
#    Updated: 2015/10/17 16:45:14 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
INCLUDE = includes/
SRCPATH = ./
OBJPATH = obj/
CFLAGS = -f macho64 #-g
SRC = $(addprefix $(SRCPATH), ft_bzero.s)
#SRC = $(addprefix $(SRCPATH), $(SRC))
OBJ = $(addprefix $(OBJPATH), $(SRC:.s=.o))
INC = $(addprefix -I, $(INCLUDE))

all: createdir $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(addprefix $(OBJPATH), %.o): $(addprefix $(SRCPATH), %.s)
	$(HOME)/.brew/bin/nasm $(CFLAGS) $< -o $@

test:
	gcc -g -Wall -Werror -Wextra main.c -I $(INC) -L./ -lfts -o tests

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)
	rm -rf tests

re: fclean all

createdir:
	mkdir -p $(OBJPATH)

.PHONY: clean fclean createdir all
