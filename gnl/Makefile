1:
	gcc -g -Wall -Wextra -Werror -c get_next_line.c -I libft/includes
	gcc -g -Wall -Wextra -Werror -c main.c -I libft/includes
	gcc -g -o test_gnl get_next_line.o main.o -L libft/ -lft

2:
	gcc -g -Wall -Wextra -Werror -c get_next_line.c -I libft/includes
	gcc -g -Wall -Wextra -Werror -c main2.c -I libft/includes
	gcc -g -o test_gnl get_next_line.o main2.o -L libft/ -lft

empty:
	gcc -Wall -Wextra -Werror -c get_next_line.c -I libft/includes
	gcc -Wall -Wextra -Werror -c mainempty.c -I libft/includes
	gcc -o test_gnl get_next_line.o mainempty.o -L libft/ -lft

stdin:
	gcc -Wall -Wextra -Werror -c get_next_line.c -I libft/includes
	gcc -Wall -Wextra -Werror -c mainstdin.c -I libft/includes
	gcc -o test_gnl get_next_line.o mainstdin.o -L libft/ -lft

clean:
	rm *.o
