/* 19_tolower */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define MaxBuf 8192

int main(int argc, char *argv[]) {
    char buf[MaxBuf];
    int fd, fsize, readCnt, i;

    if(argc != 3){
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
    
    readCnt = read(fd, buf, fsize);

    for(i = 0; i < readCnt; i ++) {
        if(isupper(buf[i])) {
            buf[i] += 32;
        }
    }

    fd = open(argv[2], O_WRONLY);
    write(fd, buf, readCnt);
}