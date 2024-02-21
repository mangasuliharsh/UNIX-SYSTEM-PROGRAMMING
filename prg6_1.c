#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int status;

    if ((pid = fork()) == -1) {
        perror("Fork Error");
        return 0;
    }

    if (pid == 0) { /* child */
        printf("\nChild: %d Waiting for parent to retrieve its exit status\n", getpid());
        exit(0);
    }

    if (pid > 0) { /* parent */
        wait(&status);
        printf("\nParent: %d\n", getpid());
        system("ps u");
    }

    return 0;
}
