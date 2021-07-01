#include <stdio.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
 
int main(int argc, char *argv[])
{
    if (fork() == 0) 
    {
        char buf[100];
        mkdir("zaliczenie", 0755);
        FILE *plik;
        plik = fopen("lista.txt", "w");

        for (int i = 1; i < argc; i++)
        {
            struct stat info;
            int status = stat(argv[i], &info);
            if (status == 0)
            {
                if (S_ISREG(info.st_mode)) 
                {
                    snprintf(buf, sizeof buf, "%ld", info.st_size);
                }
                else
                {
                    snprintf(buf, sizeof buf, "nie plik regularny");
                }
            }
            else
            {
                snprintf(buf, sizeof buf, "nie istnieje");
            }
            fprintf(plik, "%s : %s\n", argv[i], buf);
        }

        fclose(plik);
    }
    else
    {
        pid_t child_pid = wait(NULL);
        printf("PID rodzica: %d\n", getpid());
        printf("PID dziecka: %d\n", child_pid);
        printf("Program zakonczony.\n");
    }
    return 0;
}