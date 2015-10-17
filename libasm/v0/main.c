#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//void	hello(void);
//void	main2(void);
void	ft_bzero( void *s, int n );
void	ft_strcat( char *s1, const char *s2 );
int		ft_isalpha( int c );
int		ft_isdigit( int c );
int		ft_isalnum( int c );
int		ft_isascii( int c );
int		ft_isprint( int c );
int		ft_toupper( int c );
int		ft_tolower( int c );
int		ft_puts( char *s );
int		ft_strlen( char *s );
void	*ft_memset( void *h, int c, size_t len );
void	*ft_memcpy( void *h, void *s2, size_t len );
char	*ft_strdup( const char *s );

/*
void	enter(void)
{
	write( 1, "\n", 1 );
}
void	ft_putchar(char c)
{
	write( 1, &c, 1 );
}
static void	dump_value(char *val, int n)
{
	--n;
	while (n >= 0)
	{
		if ((val[n] >> 4) >= 10)
			ft_putchar((val[n] >> 4) - 10 + 'a');
		else
			ft_putchar((val[n] >> 4) + '0');
		if (val[n] % 16 >= 10)
			ft_putchar((val[n] & 0x0F) - 10 + 'a');
		else
			ft_putchar((val[n] & 0x0F) + '0');
		--n;
	}
}
*/

int		main( void )
{
	/*
// BZERO
	char	*test = malloc(3);
	test[0] = 'a';
	test[1] = 'b';
	test[2] = 0;
	dump_value(test, 3);
	enter();
	ft_bzero(test, 3);
	dump_value(test, 3);
	enter();

	*//*
// STRCAT
	printf("STRCAT\n");
	char	*test = strdup("abcd");
	char	*test2 = strdup("ba");
	test[2] = 0;
	ft_strcat( test, test2 );
	printf("%s --> abba\n", test);
	*//*
// ISALPHA
	printf("%i -> true; %i -> false\n", ft_isalpha('a'), ft_isalpha('1'));
	printf("%i -> true; %i -> false\n", ft_isalpha('Z'), ft_isalpha('{'));

	*//*
// ISDIGIT
	printf("%i -> true; %i -> false\n", ft_isdigit('1'), ft_isdigit(' '));
	printf("%i -> true; %i -> false\n", ft_isdigit('9'), ft_isdigit(0x40));

	*//*
// ISALNUM
	printf("%i -> true; %i -> false\n", ft_isalnum('1'), ft_isdigit(' '));
	printf("%i -> true; %i -> false\n", ft_isalnum('9'), ft_isdigit(0x40));
	printf("%i -> true; %i -> false\n", ft_isalnum('a'), ft_isalpha('<'));
	printf("%i -> true; %i -> false\n", ft_isalnum('Z'), ft_isalpha('{'));
	*//*
// ISASCII
	printf("%i -> true; %i -> false\n", ft_isascii(0), ft_isascii(200));
	printf("%i -> true; %i -> false\n", ft_isascii(127), ft_isascii(-3));
	return (0);
	*//*
// ISPRINT
	printf("%i -> true; %i -> false\n", ft_isprint(100), ft_isprint(0));
	printf("%i -> true; %i -> false\n", ft_isprint(126), ft_isprint(127));
	return (0);
	*//*
// TOUPPER
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('A'));
	return (0);
	*//*
// TOLOWER
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('A'));
	return (0);
	*//*
// STRLEN
	printf("%i -> 3\n", ft_strlen("aaa"));
	printf("%i -> 1\n", ft_strlen("A"));
	return (0);
	*//*
// PUTS
	printf("PUTS\n");
	ft_puts("blabliblu");
	ft_puts("b");
	*//*
// MEMSET
	printf("MEMSET\n");
	char	*test = strdup("abcd");
	char	*test2 = strdup("ba");
	ft_memset(test, 'e', 2);
	printf("%s -> eecd\n", test);
	ft_memset(test2, 'Z', 0);
	printf("%s -> ba\n", test2);
	*//*
// MEMCPY
	printf("MEMCPY\n");
	char	*test = strdup("abcd");
	char	*test2 = strdup("xxxx");
	ft_memcpy(test, test2, 2);
	printf("%s -> xxcd\n", test);
	*/
// STRDUP
	printf("STRDUP\n");
	char	*test = strdup("abcd");
	printf("%s -> abcd\n", test);
	char	*test2 = ft_strdup(test);
	printf("%s -> abcd\n", test2);
	ft_strdup("");

	return (0);
}
