#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("Fork Error");
        exit(0);
    }

    if (pid == 0) { /* child */
        printf("\nChild: %d Waiting for parent to retrieve its exit status\n", getpid());
        exit(0);
    }

    if (pid > 0) { /* parent */
        sleep(5);
        printf("\nParent: %d\n", getpid());
        system("ps u");
    }

    return 0;
}
