#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Using execl
    pid = fork();
    if (pid == 0) {
        printf("Child process: executing /bin/ls using execl\n");
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
        exit(1);
    }
    wait(NULL);

    // // Using execle
    // pid = fork();
    // if (pid == 0) {
    //     printf("Child process: executing /bin/ls using execle\n");
    //     char *envp[] = {NULL};
    //     execle("/bin/ls", "ls", NULL, envp);
    //     perror("execle failed");
    //     exit(1);
    // }
    // wait(NULL);

    // // Using execlp
    // pid = fork();
    // if (pid == 0) {
    //     printf("Child process: executing ls using execlp\n");
    //     execlp("ls", "ls", NULL);
    //     perror("execlp failed");
    //     exit(1);
    // }
    // wait(NULL);

    // // Using execv
    // pid = fork();
    // if (pid == 0) {
    //     printf("Child process: executing /bin/ls using execv\n");
    //     char *args[] = {"ls", NULL};
    //     execv("/bin/ls", args);
    //     perror("execv failed");
    //     exit(1);
    // }
    // wait(NULL);

    // // Using execvp
    // pid = fork();
    // if (pid == 0) {
    //     printf("Child process: executing ls using execvp\n");
    //     char *args[] = {"ls", NULL};
    //     execvp("ls", args);
    //     perror("execvp failed");
    //     exit(1);
    // }
    // wait(NULL);

    // // Using execvpe
    // pid = fork();
    // if (pid == 0) {
    //     printf("Child process: executing ls using execvpe\n");
    //     char *args[] = {"ls", NULL};
    //     char *envp[] = {NULL};
    //     execvpe("ls", args, envp);
    //     perror("execvpe failed");
    //     exit(1);
    // }
    // wait(NULL);

    printf("Parent process: all child processes finished execution\n");
    return 0;
}