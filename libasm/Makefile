NAME = libfts.a
TESTSNAME = tests
INCLUDE = ./
SRCPATH = ./
OBJPATH = obj/
CFLAGS = -f macho64 -g
SRCFILES = \
					 ft_bzero.s \

SRC = $(addprefix $(SRCPATH), $(SRCFILES))
OBJ = $(addprefix $(OBJPATH), $(SRCFILES:.s=.o))
INC = $(addprefix -I, $(INCLUDE))


all: createdir $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(addprefix $(OBJPATH), %.o): $(addprefix $(SRCPATH), %.s)
	$(HOME)/.brew/bin/nasm $(CFLAGS) $< -o $@

tests:
	gcc -g -Wall -Werror -Wextra main.c -I $(INC) -L./ -lfts -o $(TESTSNAME)

clean:
	rm -rf obj
	rm -rf *.dSYM

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TESTSNAME)

re: fclean all

createdir:
	mkdir -p $(OBJPATH)

.PHONY: clean fclean createdir all
