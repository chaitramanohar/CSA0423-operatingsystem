#include <stdio.h>

int main() {
    int indexBlock, fileBlocks[20], n, i;

    printf("Enter index block number: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks required: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &fileBlocks[i]);
    }

    printf("\nIndexed Allocation Table:\n");
    printf("Index Block -> %d\n", indexBlock);

    for(i = 0; i < n; i++) {
        printf("%d -> %d\n", indexBlock, fileBlocks[i]);
    }

    return 0;
}

