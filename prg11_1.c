#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signo) {
    printf("\nsignal handler: caught signal num is => %d\n", signo);
    exit(0);
}

int main() {
    signal(SIGINT, handler);

    while (1)
        printf("hello \t ");

    return 0;
}
