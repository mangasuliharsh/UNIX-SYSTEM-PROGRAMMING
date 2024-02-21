#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("Fork Error");
        exit(0);
    }

    if (pid == 0) { /* child */
        sleep(5);
        printf("\nChild: %d\tOrphan's Parent: %d\n", getpid(), getppid());
    }

    if (pid > 0) { /* parent */
        printf("\nOriginal Parent: %d\n", getpid());
        exit(0);
    }

    return 0;
}
