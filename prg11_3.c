#include <signal.h>
#include <stdio.h>

void ignoreHandler(int signo) {
    // Ignore the signal
}

int main() {
    signal(SIGINT, ignoreHandler);

    while (1)
        printf("hello\t ");

    return 0;
}
