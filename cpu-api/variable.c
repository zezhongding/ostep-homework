#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int x = 100; // 初始化变量x为100
    printf("Before fork: x = %d\n", x);

    pid_t pid = fork(); // 创建子进程

    if (pid < 0) {
        // fork失败
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // 子进程
        printf("Child process: x = %d\n", x);
        x = 200; // 修改x的值
        printf("Child process: x changed to %d\n", x);
    } else {
        // 父进程
        printf("Parent process: x = %d\n", x);
        x = 300; // 修改x的值
        printf("Parent process: x changed to %d\n", x);
    }

    return 0;
}