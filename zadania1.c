#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ROZMIAR_BUF 1

int main(int argc, char *argv[])
{
    int input_fd, output_fd;
    char bufor[ROZMIAR_BUF];
    ssize_t ret_in, ret_out;
    int counter=0;


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

    output_fd = open(strcat(argv[1], ".red"), O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(output_fd == -1)
    {
        perror(strcat(argv[1], ".red"));
        return 2;
    }

    while((ret_in = read(input_fd, &bufor, ROZMIAR_BUF)) > 0)
    {
        if(counter%3 == 0)
        {
        ret_out = write(output_fd, &bufor, ret_in);
        }
        counter++;
    }
}
