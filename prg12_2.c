#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int n, pfds[2];
    char buf[30];
    pid_t pid;

    if (pipe(pfds) == -1) {
        perror("pipe");
        exit(1);
    }

    if ((pid = fork()) == -1) {
        perror("Fork Error");
        return 0;
    }

    if (pid > 0) { // parent
        close(pfds[0]);
        write(pfds[1], "hello\n", 7);
    }

    if (pid == 0) { // child
        close(pfds[1]);
        n = read(pfds[0], buf, 7);
        write(1, buf, n);
    }

    return 0;
}
