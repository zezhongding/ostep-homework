#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("hello\n");
        _exit(0); // Ensure immediate exit without flushing buffers
    } else {
        // Parent process
        // Introduce a small delay to ensure child runs first
        usleep(100); // Sleep for 100 microseconds
        printf("goodbye\n");
    }

    return 0;
}