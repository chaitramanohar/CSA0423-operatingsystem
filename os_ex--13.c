#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n);
void bestFit(int blockSize[], int m, int processSize[], int n);
void worstFit(int blockSize[], int m, int processSize[], int n);

int main() {
    int m, n, i;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n];

    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    printf("\n--- FIRST FIT ---\n");
    firstFit(blockSize, m, processSize, n);

    printf("\n--- BEST FIT ---\n");
    bestFit(blockSize, m, processSize, n);

    printf("\n--- WORST FIT ---\n");
    worstFit(blockSize, m, processSize, n);

    return 0;
}

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int i, j;
    int b[m];

    // Copy block sizes since they get modified
    for(i = 0; i < m; i++) b[i] = blockSize[i];

    for(i = 0; i < n; i++) allocation[i] = -1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(b[j] >= processSize[i]) {
                allocation[i] = j;
                b[j] -= processSize[i];
                break;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("Process %d -> Not Allocated\n", i+1);
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int i, j;
    int b[m];

    for(i = 0; i < m; i++) b[i] = blockSize[i];
    for(i = 0; i < n; i++) allocation[i] = -1;

    for(i = 0; i < n; i++) {
        int bestIndex = -1;

        for(j = 0; j < m; j++) {
            if(b[j] >= processSize[i]) {
                if(bestIndex == -1 || b[j] < b[bestIndex])
                    bestIndex = j;
            }
        }

        if(bestIndex != -1) {
            allocation[i] = bestIndex;
            b[bestIndex] -= processSize[i];
        }
    }

    for(i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("Process %d -> Not Allocated\n", i+1);
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int i, j;
    int b[m];

    for(i = 0; i < m; i++) b[i] = blockSize[i];
    for(i = 0; i < n; i++) allocation[i] = -1;

    for(i = 0; i < n; i++) {
        int worstIndex = -1;

        for(j = 0; j < m; j++) {
            if(b[j] >= processSize[i]) {
                if(worstIndex == -1 || b[j] > b[worstIndex])
                    worstIndex = j;
            }
        }

        if(worstIndex != -1) {
            allocation[i] = worstIndex;
            b[worstIndex] -= processSize[i];
        }
    }

    for(i = 0; i < n; i++) {
        if(allocation[i] != -1)
            printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
        else
            printf("Process %d -> Not Allocated\n", i+1);
    }
}
