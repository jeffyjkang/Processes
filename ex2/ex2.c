// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    // FILE keyword, create pointer to *fp
    FILE *fp;
    // assign fp value to fopen() library call
    fp = fopen("text.txt", "r+");
    // pid_t is signed int type, represresents processID
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        fprintf(fp, "%s %s %s %d \n", "We", "are", "in", 2012);
        printf("Child! pid value is %d\n", pid);
    }
    else if (pid > 0)
    {
        fprintf(fp, "%s %s %s %d \n", "We", "are", "in", 2012);
        printf("Parent! pid value is %d\n", pid);
    }
    fclose(fp);

    return 0;
}
