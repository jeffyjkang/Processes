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
        printf("Child! pid value is %d \n", pid);

        // int execl(const char *path, const char *arg0, ... /*, (char *)0 */);
        // int execv(const char *path, char *const argv[]);
        // int execle(const char *path, const char *arg0, ... /*,
        //        (char *)0, char *const envp[]*/);
        // int execve(const char *path, char *const argv[], char *const envp[]);
        // int execlp(const char *file, const char *arg0, ... /*, (char *)0 */);
        // int execvp(const char *file, char *const argv[]);
        //
        // execlp("ls", "ls", NULL);
        //
        // char *argv[] = {"ls", "-1", 0};
        // execv("/bin/ls", argv);
        //
        char *argv[] = {"/bin/ls", "-1", 0};
        execvp(argv[0], argv);
        perror("exec");
    }
    else if (pid > 0)
    {
        printf("Parent! pid value is %d \n", pid);
    }

    return 0;
}
