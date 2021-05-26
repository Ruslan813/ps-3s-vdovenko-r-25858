#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int input_fd, output_fd;
    char buffer[BUF_SIZE];
    ssize_t ret_in, ret_out;
    char f;

    f = strcat(argv[1], ".red");

    if(argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s file_origin file_destination\n", argv[0]);
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);
    if(input_fd == -1)
    {
        perror(argv[1]);
        return 2;
    }

    output_fd = open(f, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(output_fd == -1)
    {
        perror(f);
        return 2;
    }


}
