#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("usage: ./a.out Source_FileName Link_FileName\n");
        exit(0);
    }

    if (link(argv[1], argv[2]) == -1)
        perror("link error");
    else
        printf("Link has been created with the name %s\n", argv[2]);

    return 0;
}
