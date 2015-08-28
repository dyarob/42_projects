# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <amerle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/02 01:52:07 by amerle            #+#    #+#              #
#    Updated: 2013/12/07 14:29:53 by avannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = test.prog
PROGDIR = ..#/getnextline
LIBDIR = $(PROGDIR)/libft
LDFLAGS = -L$(LIBDIR) -lft
CFLAGS = -Wall -Werror -Wextra -ggdb3 -I$(PROGDIR) -I$(LIBDIR)/includes
SRCS = 	main.c \
		$(PROGDIR)/get_next_line.c

OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

lib:
	@make -C $(LIBDIR)

lib_clean:
	@make -C $(LIBDIR) clean

lib_fclean:
	@make -C $(LIBDIR) fclean

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^ $(LDFLAGS) && ./$(NAME)
	make -C . fclean

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
