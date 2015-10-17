#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfanton <gfanton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:57:53 by gfanton           #+#    #+#              #
#    Updated: 2015/01/23 09:22:34 by avannest         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NNAME = fts
INCLUDE = includes/
SRCPATH = ./
OBJPATH = obj/
CFLAGS = -f macho64 -g
C = \033[1;34m
SRCS = \
	   ft_bzero.s \
	   ft_strcat.s \
	   ft_isalpha.s \
	   ft_isdigit.s \
	   ft_isalnum.s \
	   ft_isascii.s \
	   ft_isprint.s \
	   ft_toupper.s \
	   ft_tolower.s \
	   ft_strlen.s \
	   ft_puts.s \
	   ft_memset.s \
	   ft_memcpy.s \
	   ft_strdup.s \

NAME = lib$(NNAME).a
CLNAME = l$(NNAME)
V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
CC = $(SILENCE)$(HOME)/.brew/bin/nasm
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf
SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRCS:.s=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
U = $(C)[$(NAME)]----->\033[0m
OBJDIR = $(addprefix $(OBJPATH), $(OBJS))

all: createdir $(NAME)

$(NAME): $(OBJDIR)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJDIR)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

$(addprefix $(OBJPATH), %.o): $(addprefix $(SRCPATH), %.s)
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) $(CFLAGS) $< -o $@
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

test:
	gcc -g -Wall -Werror -Wextra $(addprefix -I, $(INCLUDE)) main.c -L./ -lfts

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) obj
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

createdir:
	$(SILENCE) mkdir -p $(OBJPATH)

.PHONY: clean fclean createdir all
