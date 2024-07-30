#include <stdio.h>
#include "../include/stdlib.h"

int main()
{	
	char *string = strdup("0.1.2.3.4.5.6.7.8.9\0");
	char *strip_of_string = strstrip(strdup(string), strdup(".\0"));
	printf("strstrip(\"%s\", \".\") = %s\n", string, strip_of_string);
	return 0;
}
