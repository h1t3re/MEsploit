#include <stdio.h>
#include "../include/stdlib.h"

int main()
{
	char *Casa = "Casa\0";
	char *Casablanca = "Casablanca\0";
	printf("strcontains(\"%s\", \"%s\") = %d\n", strdup(Casablanca), strdup(Casa), strcontains(strdup(Casablanca), strdup(Casa)));
	printf("strcontains(\"%s\", \"%s\") = %d\n", strdup(Casablanca), strdup("casa\0"), strcontains(Casablanca, strdup("casa\0")));
	return 0;
}
