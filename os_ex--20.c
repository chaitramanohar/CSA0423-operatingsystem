#include <stdio.h>

int readcount = 0;   // number of active readers
int mutex = 1;       // semaphore to protect readcount
int wrt = 1;         // semaphore for writer (exclusive lock)

// Wait operation
void wait(int *s) {
    while (*s <= 0); // busy wait (simulation)
    (*s)--;
}

// Signal operation
void signal(int *s) {
    (*s)++;
}

void reader() {
    wait(&mutex);         // lock readcount
    readcount++;
    
    if (readcount == 1)   // first reader locks writer
        wait(&wrt);

    signal(&mutex);       // unlock readcount

    printf("Reader is reading... Active readers = %d\n", readcount);

    wait(&mutex);         // lock readcount
    readcount--;

    if (readcount == 0)   // last reader unlocks writer
        signal(&wrt);

    signal(&mutex);
}

void writer() {
    wait(&wrt);   // writer gets exclusive access

    printf("Writer is writing...\n");

    signal(&wrt); // release exclusive access
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Reader-Writer Problem Simulation ===\n");
        printf("1. Reader enters\n");
        printf("2. Writer enters\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reader();
                break;

            case 2:
                if (readcount == 0)
                    writer();
                else
                    printf("Writer waiting... Readers are active.\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

