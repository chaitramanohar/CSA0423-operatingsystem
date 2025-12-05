#include <stdio.h>

int main() {
    int n, m, i, j;
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    int blockSize[n], blockAlloc[n];
    for(i=0; i<n; i++)
        blockAlloc[i] = -1;
    
    printf("Enter size of each block: ");
    for(i=0; i<n; i++)
        scanf("%d", &blockSize[i]);
    
    printf("Enter number of processes: ");
    scanf("%d", &m);
    int processSize[m];
    printf("Enter size of each process: ");
    for(i=0; i<m; i++)
        scanf("%d", &processSize[i]);
    
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(blockSize[j] >= processSize[i]) {
                blockAlloc[j] = i;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i=0; i<m; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        int allocated = 0;
        for(j=0; j<n; j++) {
            if(blockAlloc[j] == i) {
                printf("%d\n", j+1);
                allocated = 1;
                break;
            }
        }
        if(!allocated)
            printf("Not Allocated\n");
    }
    
    return 0;
}

