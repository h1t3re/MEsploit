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
		system("echo \"$(ps axfj | grep ssh)\" > ps_ssh.txt");
		ps_aux = read_file_v1("/home/h1t3re/projects/MEsploit/modules/ssh_killer/ps_ssh.txt\0");
		ps = strsplit_v1(strdup(ps_aux), strdup("\n\0"));
		while(ps[i] != '\0')
		{
			array = strsplit_v1(strdup(ps[i]), strdup(" \0"));
			if(strcontains(strdup(ps[i]), strdup("sshd\0")) == 0)
			{
				printf("Killing process with id %s\n", strdup(array[1]));
				system(strconcatenate(strdup("kill -9 \0"), strdup(array[1])));
			}
			i++;
		}
		i = 0;
	}
	return 0;
}
