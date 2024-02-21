#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("\nOriginal Process: %d\tParent Process: %d\n", getpid(), getppid());

    if ((pid = vfork()) == -1) {
        perror("Fork Error");
        exit(0);
    }

    if (pid == 0) { /* child */
        printf("\nChild Process: %d\tParent Process: %d\n", getpid(), getppid());
        _exit(0);  // Child process should use _exit to avoid flushing parent's buffers
    }

    if (pid > 0) { /* parent */
        printf("\nOriginal Process: %d\tParent Process: %d\n", getpid(), getppid());
    }

    printf("\nEnd of Main\n");

    return 0;
}
