// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    // pid_t signed int type rep process ID
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        execlp("ls", "ls", NULL);
        perror("exec");
        printf("Child! pid value is %d \n", pid);
    }
    else if (pid > 0)
    {
        printf("Parent! pid value is %d \n", pid);
    }

    return 0;
}
