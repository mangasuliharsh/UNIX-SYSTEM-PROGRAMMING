#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void pr_exit(int status) {
    if (WIFEXITED(status))
        printf("\nNormal termination, exit status = %d", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("\nAbnormal termination, signal number = %d", WTERMSIG(status));
    else if (WIFSTOPPED(status))
        printf("\nChild stopped, signal number = %d", WSTOPSIG(status));
}

int main() {
    pid_t pid, childpid;
    int status;

    if ((pid = fork()) == -1) {
        perror("\nFork Error");
        return 0;
    }

    if (pid == 0)
        exit(23);

    childpid = wait(&status);
    pr_exit(status);

    if ((pid = fork()) == -1) {
        perror("\nFork Error");
        return 0;
    }

    if (pid == 0)
        abort();

    childpid = wait(&status);
    pr_exit(status);

    if ((pid = fork()) == -1) {
        perror("\nFork Error");
        return 0;
    }

    if (pid == 0) {
        // Corrected: Handling division by zero gracefully
        int res = 5 / 0;
        exit(0);
    }

    childpid = wait(&status);
    pr_exit(status);

    return 0;
}
