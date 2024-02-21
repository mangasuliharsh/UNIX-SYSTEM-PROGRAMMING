#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;

    if (argc <= 1) {
        printf("No files to delete. Usage: ./a.out FileName1 FileName2 ..\n");
        exit(1);
    }

    for (i = 1; i < argc; i++) {
        if (unlink(argv[i]) == -1)
            perror("Error in deleting...\n");
        else
            printf("The file %s is deleted...\n", argv[i]);
    }

    return 0;
}
