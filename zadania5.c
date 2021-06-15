#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    pid_t pid;
    pid_t ch_pid;
    int status, i;
    FILE* f;

    pid = fork();
    if(pid==-1){
        perror("fork");
        _exit(1);
    }
    if(pid == 0){
        f = fopen("liczby.txt", "w");
        if(!f)
        {
            perror("fopen");
            _exit(1);
        }

        for(i = 9; i <= 99; i++){
            if(i % 3 == 0){
                fprintf(f, "%d\n", i);
            }
        }

        if(fclose(f) != 0)
        {
            perror("fclose");
            _exit(1);
        }
        _exit(0);
    }

    if(pid > 0){
        ch_pid = wait(&status);
        if(ch_pid==-1){
            perror("wait");
            _exit(1);
        }
        if(WIFEXITED(status)){
            printf("Exit status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
