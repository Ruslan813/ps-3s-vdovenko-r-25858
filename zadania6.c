#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid_t ch_pid;
    int status;
    int ret;
    char *cwd = getcwd(NULL, 0);

    pid = fork();
    if(pid == -1)
    {
        perror("fork");
        _exit(1);
    }
    if(pid > 0)
    {
        printf("(P) Fork: %d\tPID: %d\tPPID: %d\n", (int) pid, (int) getpid(), (int) getppid());
        ch_pid = wait(&status);

        ret = execlp("ls","ls", "-l", cwd, (char *)NULL);
        if(ret == -1)
        {
            perror("exec");
            return 1;
        }

        if(ch_pid == -1)
        {
            perror("wait");
            _exit(2);
        }
    }
    if(pid == 0)
    {
        printf("(C) Fork: %d\tPID: %d\tPPID: %d\n", (int) pid, (int) getpid(), (int) getppid());
        sleep(1);
        _exit(4);
    }
    return 0;
}
