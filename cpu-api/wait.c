#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // child process
        printf("Child process (PID: %d) is running.\n", getpid());
        sleep(2); // simulate some work
        printf("Child process (PID: %d) is exiting.\n", getpid());
        exit(42); // exit with a specific status
    } else {
        // parent process
        int status;
        pid_t waited_pid = wait(&status); // wait for child process to finish

        if (waited_pid == -1) {
            perror("wait failed");
            exit(1);
        }

        printf("Parent process: waited for child process with PID %d.\n", waited_pid);

        if (WIFEXITED(status)) {
            printf("Child exited with status %d.\n", WEXITSTATUS(status));
        } else {
            printf("Child did not exit normally.\n");
        }
    }

    return 0;
}