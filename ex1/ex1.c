// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    // initialize type int x to 100
    int x = 100;
    // pid_t is a signed integer type capable of representing a process ID, assign it to fork, (way to create new processes)
    pid_t pid = fork();
    // if no fork
    if (pid < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    // we are in the child
    else if (pid == 0)
    {
        printf("Child! pid value is %d, value of x before reassign is %d\n", pid, x);
        x = 10;
        printf("Child! pid value is %d, value of x after reassign is %d\n", pid, x);
    }
    // we are in the parent
    else if (pid > 0)
    {
        // wait(NULL);
        printf("Parent! pid value is %d, value of x before reassign is %d\n", pid, x);
        x = 20;
        printf("Parent! pid value is %d, value of x after reassign is %d\n", pid, x);
    }

    return 0;
}
