#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("usage: ./a.out Source_FileName Link_FileName\n");
        exit(1);
    }

    if (link(argv[1], argv[2]) == -1)
        perror("Link error\n");
    else
        unlink(argv[1]); // deletes the first file

    return 0;
}
