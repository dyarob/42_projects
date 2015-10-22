#include "libfts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NBROFTESTS 4

int	test_bzero(void) {
	struct {const char* s; size_t n;} t[NBROFTESTS] = {
		{"hello", 5},
		{"", 0},
		{NULL, 0},
		{"hello", 3}};
	void	*s1 = NULL, *s2 = NULL;

	puts("Testing ft_bzero:");

	for (int i=0; i<3; ++i) {
		s1 = (void*)strdup(t[i].s);
		s2 = (void*)strdup(t[i].s);
		bzero(s1, t[i].n);
		ft_bzero(s2, t[i].n);
		if (strcmp(s1, s2)) {
			free(s1);free(s2);
			puts("FAILED");
			return (-1);
		}
		free(s1);free(s2);
	}

	puts("Complete.");
	return 0;
}

int	main(void) {
	puts("Hello tests!");

	if (test_bzero())
		exit(-1);

	return 0;
}
