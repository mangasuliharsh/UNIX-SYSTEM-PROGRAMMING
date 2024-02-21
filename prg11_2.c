#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    signal(SIGINT, SIG_DFL);

    while(1)
        printf("hello\t");

    return 0;
}
