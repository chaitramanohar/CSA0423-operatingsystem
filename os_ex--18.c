#include <stdio.h>

int mutex = 1;      // binary semaphore
int full = 0;       // count of full slots
int empty = 5;      // count of empty slots (buffer size)
int x = 0;          // item counter

void wait(int *s) {
    while (*s <= 0);   // busy wait
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    wait(&mutex);
    wait(&empty);

    x++;
    printf("Producer produced item %d\n", x);

    signal(&mutex);
    signal(&full);
}

void consumer() {
    wait(&mutex);
    wait(&full);

    printf("Consumer consumed item %d\n", x);
    x--;

    signal(&mutex);
    signal(&empty);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Producer-Consumer Menu ===\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is FULL! Cannot produce.\n");
                break;

            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is EMPTY! Cannot consume.\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

