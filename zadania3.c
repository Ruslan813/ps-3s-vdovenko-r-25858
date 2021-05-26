#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *wp;
    FILE *wr;
    unsigned long counter = 0;
    int ch;
    char f;

    f = strcat(argv[1], ".red");
    printf("\n File:\n %s \n", argv[1]);

    wr = fopen(f, a+);
    if(wr == NULL)
    {
        printf("Can't open file slowa.txt\n");
        return 2;
    }

    if(argc != 2)
    {
        printf("Usage: %s file_name\n", argv[0]);
        return 1;
    }

    wp = fopen(argv[1], "r");
    if(!wp)
    {
        perror(argv[1]);
        return 1;
    }

    while((ch = fgetc(wp)) != EOF)
    {

        fseek(wp, counter, SEEK_SET);
        counter+=3;
        fputc(ch, wr);
    }

    fclose(wp);





    return 0;
}
