#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd, n, skval;
    char c;

    if (argc != 2) {
        printf("usage: ./a.out FileName\n");
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        printf("Can't open file %s for Reading\n", argv[1]);
        exit(0);
    }

    while ((n = read(fd, &c, 1)) == 1) {
        printf("\nChar: %c", c);
        skval = lseek(fd, 99, SEEK_CUR);
        printf("\nNew seek value is: %d", skval);
    }

    printf("\n");

    exit(0);
}
