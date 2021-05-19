#include <stdio.h>
# include <string.h>
int main(int argc, char* argv[])
 {
 FILE* wp;
 FILE* out;
 int fchar;
 unsigned long i = 1;
 if(argc != 2)
 { printf("Usage: %s fileName\n", argv[0]);
 return 2;
    }
    if((wp = fopen(argv[1], "r")) == NULL)
        {
          fprintf(stderr, "Couldn't open file: %s\n", argv[1]); return 1;
    }
    if((out = fopen(strcat(argv[1], ".red"), "w")) == NULL)
	 {
		 fprintf(stderr, "Couldn't open file: %s\n", argv[1]);
		 return 3;
    }
while((fchar = fgetc(wp)) != EOF) 
	{
		 if (i % 3 == 0)
			 {
				 fputc(fchar, out);
       			 }
       		 i++;
    	}
 fclose(wp);
