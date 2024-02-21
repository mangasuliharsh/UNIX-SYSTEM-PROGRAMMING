#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    struct stat sb;

    if (argc != 2) {
        printf("Usage: ./a.out FileName\n");
        exit(0);
    }

    if (stat(argv[1], &sb) == -1) {
        perror("Error in stat");
        exit(0);
    }

    printf("File: %s is ", argv[1]);

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:
            printf("Block device file\n");
            break;
        case S_IFCHR:
            printf("Character device file\n");
            break;
        case S_IFDIR:
            printf("Directory file\n");
            break;
        case S_IFIFO:
            printf("FIFO/pipe file\n");
            break;
        case S_IFLNK:
            printf("Symbolic link file\n");
            break;
        case S_IFREG:
            printf("Regular file\n");
            break;
        default:
            printf("Unknown file?\n");
    }

    printf("and its Inode number is: %ld\n", (long)sb.st_ino);

    return 0;
}
