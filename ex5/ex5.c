// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here
    // buffer that will hold incoming data that is being written
    char inbuf[MSGSIZE];
    // two-element array to hold the read & write file descipros
    int p[2];
    // establish pipe, passing it the p array so that it gets populated by the r&w f descriptors
    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    // pid_t signed int type rep process ID
    pid_t pid = fork();
    // if fork is -1 return error
    if (pid < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    // for child processes
    else if (pid == 0)
    {
        // write 16 bytes of data to the write file descriptor
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    // for parent processes
    else if (pid > 0)
    {
        for (int i = 0; i < 3; i++)
        {
            // read 16 bytes of data from the read file descriptor
            read(p[0], inbuf, MSGSIZE);
            printf("%s \n", inbuf);
        }
    }

    return 0;
}
