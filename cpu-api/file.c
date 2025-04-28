#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // 打开文件
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        close(fd);
        exit(1);
    }

    if (pid == 0) {
        // 子进程
        const char *child_msg = "Child process writing...\n";
        for (int i = 0; i < 5; i++) {
            if (write(fd, child_msg, sizeof("Child process writing...\n") - 1) < 0) {
                perror("write");
                close(fd);
                exit(1);
            }
        }
    } else {
        wait(NULL);
        // 父进程
        const char *parent_msg = "Parent process writing...\n";
        for (int i = 0; i < 5; i++) {
            if (write(fd, parent_msg, sizeof("Parent process writing...\n") - 1) < 0) {
                perror("write");
                close(fd);
                exit(1);
            }
        }

        // 等待子进程完成
       
    }

    // 关闭文件
    close(fd);
    return 0;
}