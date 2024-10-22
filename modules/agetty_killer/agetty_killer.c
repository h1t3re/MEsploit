#include <stdio.h>
#include "../../include/stdlib.h"
#include <stdlib.h>
#include <signal.h>

int main()
{
	int i = 0;
	int j = 0;
	char **array = NULL;
	char *ps_aux;
	char **ps;
	while(1)
	{
		system("echo \"$(ps axfj | grep agetty)\" > ps_co_s.txt");
		ps_aux = read_file("./ps_co_s.txt\0");
		ps = strsplit_v1(strdup(ps_aux), strdup("\n\0"));
		while(ps[i] != '\0')
		{
			array = strsplit_v1(strdup(ps[i]), strdup(" \0"));
			while(array[j] != '\0')
			{
				if(strcontains(ps[i], strdup("agetty\0")) == 0)
				{
					printf("Killing process with id %s\n", strdup(array[1]));
					kill(strdup(array[1]), SIGTERM);
				}
				j++;
			}
			i++;
		}
	}
	return 0;
}
