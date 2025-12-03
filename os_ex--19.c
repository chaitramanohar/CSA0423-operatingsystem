#include <stdio.h>

int mutex = 1;   // mutex lock: 1 = unlocked, 0 = locked
int counter = 0; // shared resource

void wait(int *m) {
    while (*m <= 0);  // busy wait
    (*m)--;
}

void signal(int *m) {
    (*m)++;
}

void process1() {
    wait(&mutex); // lock
    printf("Process 1 entered critical section.\n");

    counter++;
    printf("Process 1 incremented counter to %d\n", counter);

    signal(&mutex); // unlock
    printf("Process 1 exited critical section.\n");
}

void process2() {
    wait(&mutex); // lock
    printf("Process 2 entered critical section.\n");

    counter++;
    printf("Process 2 incremented counter to %d\n", counter);

    signal(&mutex); // unlock
    printf("Process 2 exited critical section.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Mutex Lock Synchronization ===\n");
        printf("1. Run Process 1\n");
        printf("2. Run Process 2\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mutex == 1)
                    process1();
                else
                    printf("Critical section locked! Process 1 must wait.\n");
                break;

            case 2:
                if (mutex == 1)
                    process2();
                else
                    printf("Critical section locked! Process 2 must wait.\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

