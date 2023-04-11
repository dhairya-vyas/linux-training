#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PIPE_NAME "/tmp/myfifo"
#define BUFFER_SIZE 1024

struct Contact {
    char name[50];
    char address[100];
    char phone[20];
};

int main() {
    struct Contact contact1 = {"John Doe", "123 Main St", "555-1234"};
    struct Contact contact2;

    int fd;
    char buffer[BUFFER_SIZE];

    mkfifo(PIPE_NAME, 0666);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) { // parent process
        fd = open(PIPE_NAME, O_WRONLY);
        if (fd == -1) {
            perror("open failed");
            exit(1);
        }
        write(fd, &contact1, sizeof(struct Contact));
        close(fd);
    } else { // child process
        fd = open(PIPE_NAME, O_RDONLY);
        if (fd == -1) {
            perror("open failed");
            exit(1);
        }
        read(fd, &contact2, sizeof(struct Contact));
        printf("Received contact:\nName: %s\nAddress: %s\nPhone: %s\n",
            contact2.name, contact2.address, contact2.phone);
        close(fd);
    }

    unlink(PIPE_NAME);

    return 0;
}
