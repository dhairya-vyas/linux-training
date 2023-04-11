#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

struct Message {
    int sender_pid;
    char message_text[SHM_SIZE - sizeof(int)];
};

int main() {
    int shmid;
    key_t key = 1234;
    char *shm;
    struct Message *msg;
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

    msg = (struct Message *)shm;

    if (pid > 0) { // parent process
        while (1) {
            printf("Enter message to child: ");
            fgets(msg->message_text, SHM_SIZE - sizeof(int), stdin);
            msg->sender_pid = getpid();
            if (strcmp(msg->message_text, "quit\n") == 0) {
                break;
            }
        }
    } else { // child process
        while (1) {
            while (msg->sender_pid == getpid()) {
                // wait for parent to write message
            }
            printf("Received message from parent (pid %d): %s", msg->sender_pid, msg->message_text);
            if (strcmp(msg->message_text, "quit\n") == 0) {
                break;
            }
            msg->sender_pid = getpid();
            printf("Enter message to parent: ");
            fgets(msg->message_text, SHM_SIZE - sizeof(int), stdin);
        }
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
