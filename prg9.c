#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void charatatime(char *str) {
    char *ptr;
    int c;
    setbuf(stdout, NULL); /* set unbuffered */
    for (ptr = str; (c = *ptr++) != 0; )
        putc(c, stdout);
}

int main(int argc, char *argv[]) {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("Fork Error");
        return 0;
    }

    if (pid == 0)
        charatatime("CHILD PROCESS WRITING DATA TO THE TERMINAL\n");
    if (pid > 0)
        charatatime("parent process writing the data to terminal\n");

    return 0;
}
