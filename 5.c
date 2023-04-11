#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZE 16

int main() {
    char* str1 = "Hello, world!";
    char str2[MSGSIZE];

    int p[2];

    if (pipe(p) < 0) {
        perror("pipe failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) { // parent process
        close(p[0]);
        write(p[1], str1, MSGSIZE);
        close(p[1]);
    } else { // child process
        close(p[1]);
        read(p[0], str2, MSGSIZE);
        printf("Received string: %s\n", str2);
        close(p[0]);
    }

    return 0;
}
