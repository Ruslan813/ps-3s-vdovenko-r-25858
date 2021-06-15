#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int input_fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);

    if(input_fd == -1)
    {
        perror(argv[1]);
        return 2;
    }

    for(int i=0; i<10; i++)
    {
        int n = (rand() % 91) + 9;
        char buffer[12];
        sprintf(buffer, "%d\n", n);
        write(input_fd, buffer, strlen(buffer));
    }

    return 0;

}

