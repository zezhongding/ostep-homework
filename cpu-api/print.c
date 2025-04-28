#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process: Closing standard output.\n");
        close(STDOUT_FILENO); // Close standard output

        // Attempt to print after closing stdout
        printf("This will not be printed to the terminal.\n");
    } else {
        // Parent process
        printf("Parent process: Child PID is %d\n", pid);
    }

    return 0;
}