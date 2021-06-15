#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    long n = 0;
    char buffer;
    int input_fd = open(argv[1], O_RDONLY);

    if(input_fd == -1)
    {
        perror(argv[1]);
        return 2;
    }

    off_t l = lseek(input_fd, 0, SEEK_END);
    lseek(input_fd, 0, SEEK_SET);

    while(lseek(input_fd, 0, SEEK_CUR) < l)
    {
        read(input_fd, &buffer, 1);
        if (buffer >= 48 && buffer <= 57)
        {
            n = n*10+buffer-48;
        }
        if(buffer == '\n')
        {
            printf("%ld\n", n*3);
            n = 0;
        }
    }
    
    return 0;

}
