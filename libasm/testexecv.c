#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int	ret = 0;
	puts("testing execv + segv!");
	//execv("tests", NULL);
	ret = system("./tests");
	printf("still here! with ret value %d", ret);
	return 0;
}
