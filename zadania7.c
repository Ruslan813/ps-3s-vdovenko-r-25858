#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void sig_usr(int);

int main(void)
{
    FILE *f;

    printf("PID: %d\nPPID: %d\n", (int) getpid(), (int) getppid());

    if(signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        perror("sigusr1");
        _exit(1);
    }
    if(signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        perror("sigusr2");
        _exit(1);
    }

    f = fopen("pid.txt", "w+");
    if(!f){
        perror("fopen");
        _exit(1);
    }
    
    fprintf(f, "%d\n", (int) getpid());
    fclose(f);
    
    for(;;)
    {
        pause();
    }

    return 0;
}

void sig_usr(int signo){
    FILE *f;
    if(signo == SIGUSR1){
        printf("sigusr1\n");
        f = fopen("pid.txt", "ab+");
        if(!f){
            perror("fopen");
            _exit(1);
        }
        fprintf(f, "%d\n", (int) getppid());
        fclose(f);
    }else if(signo==SIGUSR2){
        printf("sigusr2\n");
        fclose(fopen("pid.txt", "w"));
        _exit(1);
    }else{
        printf("Another SIG %d\n",signo);
    }

}
