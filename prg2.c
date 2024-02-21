#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int n, fd1, fd2;
    char buf[10];

    if (argc != 3) {
        printf("usage: ./a.out Source_FileName Destination_FileName\n");
        return 1;
    }

    if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
        printf("Can't open file %s for Reading\n", argv[1]);
        return 1;
    }

    if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0744)) == -1) {
        printf("Can't open file %s for Writing\n", argv[2]);
        return 1;
    }

    while ((n = read(fd1, buf, 1)) > 0) {
        write(STDOUT_FILENO, buf, n);  // write to terminal
        write(fd2, buf, n);  // write to file
    }

    close(fd1);
    close(fd2);

    return 0;
}
