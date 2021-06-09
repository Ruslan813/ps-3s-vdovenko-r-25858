#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    DIR* d;
    FILE* file;
    struct dirent* dir;
    struct stat buf;
if (opendir("results") == NULL){
        if (mkdir("results", 0777) == -1){
            perror("mkdir err");
            return 1;
        }
    }
    d = opendir("/etc");
    if (d==NULL){
       perror("dir opening err");
       return 2;
    }
    file = fopen("results/etc_dir.out", "w");
    if (file == NULL){ 
        perror("file opening/creating err");
        return 3;
    }
    rewinddir(d);
    while ((dir = readdir(d)) != NULL){
           if (dir->d_type == DT_DIR){
            fputs(dir->d_name, file);
            fputc('\n', file);
        }
    }
    closedir(d);
    fclose(file);

    d = opendir("/etc/sysconfig");
    if (d==NULL){ perror("dir opening err"); 
        return 4;
    }

    file = fopen("results/sysconfig.out", "w");
    if (file==NULL){ 
        perror("file opening/creating err");
        return 5;
    }
    rewinddir(d);
    while ((dir = readdir(d)) != NULL){
        if (dir->d_type == DT_REG){
            char path[] = "/etc/sysconfig/";
            stat(strcat(path dir->d_name), &buf);
            if (!(buf.st_mode & S_IRWXO)){
                fputs(dir->d_name, file);
                fputc('\n', file);
            }
        }
    }
    closedir(d);
    fclose(file);
    return 0;
}
