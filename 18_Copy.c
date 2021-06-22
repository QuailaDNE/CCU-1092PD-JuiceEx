/* 18_Copy */
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define MaxBuf 8192

void main(int argc, char *argv[]) {
    char buf[MaxBuf];
    int fd_in, fd_out;
    int readCnt, fsize;

    if(argc != 3){
        fprintf(stderr, "usage: %s sourceFile targetFile\n", argv[0]);
        exit(1);
    }

    fd_in = open(argv[1], O_RDONLY);
    if(fd_in < 0){
        fprintf(stderr, "open error: %s\n", argv[1]);
        exit(1);
    }

    fd_out = open(argv[2], O_CREAT|O_WRONLY, 0600);
    if(fd_out < 0){
        fprintf(stderr, "open error: %s\n", argv[2]);
        exit(1);
    }
    
    fsize = lseek(fd_in, 0, SEEK_END);
    lseek(fd_in, 0, SEEK_SET);

    readCnt = read(fd_in, buf, fsize);
    write(fd_out, buf, readCnt);
}