#include <stdio.h>
#include <stdlib.h>

struct Block {
    int block_no;
    struct Block *next;
};

int main() {
    int n, i;
    printf("Enter number of blocks in file: ");
    scanf("%d", &n);

    struct Block *head = NULL, *temp = NULL, *newBlock;

    for (i = 1; i <= n; i++) {
        newBlock = (struct Block*)malloc(sizeof(struct Block));
        newBlock->block_no = i;
        newBlock->next = NULL;

        if (head == NULL)
            head = newBlock;
        else
            temp->next = newBlock;

        temp = newBlock;
    }

    printf("\nFILE BLOCK CHAIN (Linked Allocation):\n");
    temp = head;
    while (temp != NULL) {
        printf("[Block %d] -> ", temp->block_no);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

