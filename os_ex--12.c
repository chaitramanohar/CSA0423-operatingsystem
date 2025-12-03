#include <stdio.h>
#include <windows.h>

#define NUM_PHILOSOPHERS 5

HANDLE forks[NUM_PHILOSOPHERS];   // semaphores for forks
int phil_id[NUM_PHILOSOPHERS];    // store philosopher IDs safely

DWORD WINAPI philosopher(void *id_ptr) {
    int id = *(int *)id_ptr;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        Sleep(1000);

        WaitForSingleObject(forks[left], INFINITE);
        printf("Philosopher %d picked left fork %d\n", id, left);

        WaitForSingleObject(forks[right], INFINITE);
        printf("Philosopher %d picked right fork %d\n", id, right);

        printf("Philosopher %d is eating...\n", id);
        Sleep(1000);

        ReleaseSemaphore(forks[left], 1, NULL);
        ReleaseSemaphore(forks[right], 1, NULL);

        printf("Philosopher %d put down forks %d & %d\n\n", id, left, right);
    }

    return 0;
}

int main() {
    HANDLE threads[NUM_PHILOSOPHERS];
    int i;

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        forks[i] = CreateSemaphore(NULL, 1, 1, NULL);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        phil_id[i] = i;     // store ID
        threads[i] = CreateThread(NULL, 0, philosopher, &phil_id[i], 0, NULL);
    }

    WaitForMultipleObjects(NUM_PHILOSOPHERS, threads, TRUE, INFINITE);

    return 0;
}

