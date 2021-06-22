/* 21_reverse */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MaxBuf 8192

int main(int argc, char *argv[]) {
    char buf1[MaxBuf];
    char buf2[MaxBuf];
    int fd, fsize, readCnt, i;

    if(argc != 3) {
        fprintf(stderr, "usage: %s tolower file\n", argv[0]);
        exit(1);
    }

    if(strcmp(argv[1], "reverse") != 0){
        fprintf(stderr, "usage: %s tolower file\n", argv[0]);
        exit(1);
    }

    fd = open(argv[2], O_RDONLY);
    if(fd < 0) {
        fprintf(stderr, "open error: %s\n", argv[2]);
        exit(1);
    }

    fsize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    readCnt = read(fd, buf1, fsize);

    for(i = 0; i < readCnt; i ++) {
        buf2[i] = buf1[readCnt - 1 - i];
    }

    fd = open(argv[2], O_WRONLY);
    write(fd, buf2, readCnt);
}