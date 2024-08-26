#include <unistd.h>
#include <stdio.h>
#include "../../include/stdlib.h"
#include <stdlib.h>
#include <sys/wait.h>

int n_by_2(int n)
{
        return 2*n;
}

int n_by_3(int n)
{
        return 3*n;
}

void interprocess_communication_with_injection()
{
        int fd0[2];
        int fd1[2];
        int pid;
        char *name;
        char *buffer;
        int i = 1;
        int result = 0;
        int nbytes = 0;
        int rbytes = 0;
        int nbits = 0;
        int nbits0 = 0;
        int c = 0;
        int *array = (int *)malloc(4*sizeof(int));
        int *array0 = (int *)malloc(4*sizeof(int));
        pid = fork();
        if(pid == 0)
        {
                pipe(fd0);
                close(fd0[0]);
                close(fd0[1]);
                close(fd1[1]);
                while(1)
                {
                        name = read_io();
                        while(name[nbytes] != '\0')
                        {
                                convert_integer_to_binary(array, name[nbytes], 1, 4);
                                while(nbits < 4)
                                {
                                        write(fd1[0], array[nbits], 1);
                                        nbits++;
                                }
                                write(fd1[0], 9, sizeof(int));
                                nbits = 0;
                                nbytes++;
                        }
                        write(fd1[0], 8, 1);
                        free(name);
                        nbytes = 0;
                }
        }else if(pid > 0){
                pipe(fd1);
                while(1)
                {
                        buffer = (char *)malloc(sizeof(char));
                        buffer[0] = ' ';
                        close(fd0[0]);
                        close(fd1[0]);
                        close(fd1[1]);
                        //printf("in parent with pid = %d\n", pid);
                        wait(NULL);
                        while(read(fd0[1], &array0[nbits0], sizeof(char)) > 0)
                        {
                                printf("%c\n", array0[nbits0]);
                                if(array0[nbits0] == 9)
                                {
                                        buffer[rbytes] = convert_binary_to_integer(array0, 4);
                                        if(buffer[rbytes] == '\n')
                                                break;
                                        rbytes++;
                                        buffer = (char *)realloc(buffer, (rbytes+1)*sizeof(char));
                                }
                                if(nbits0 == 3)
                                        nbits0 = 0;
                                nbits0++;
                        }
                        nbits0 = 0;
                        buffer[rbytes] = '\0';
                        //printf("buffer = %s\n", buffer);
                        rbytes = 0;
                        if(strcmp(buffer, "n_by_2\n\0") == 0)
                        {
                                result = n_by_2(i);
                                //printf("%d\n", result);
                        }else if(strcmp(buffer, "n_by_3\n\0") == 0)
                        {
                                result = n_by_3(i);
                                //printf("%d\n", result);
                        }
                        //printf("result[%d] = %d\n", i, result);
                        i = i +1;
                        free(buffer);
                }
        }
}

int main()
{
        interprocess_communication_with_injection();
        return 0;
}
