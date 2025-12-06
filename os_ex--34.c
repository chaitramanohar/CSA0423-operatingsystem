#include <stdio.h>

int main() {
    int file[50], start, length, i;

    for(i = 0; i < 50; i++)
        file[i] = 0;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter length of file: ");
    scanf("%d", &length);

    printf("\nAllocating blocks...\n");

    for(i = start; i < start + length; i++) {
        if(file[i] == 0) {
            file[i] = 1;
            printf("Block %d allocated\n", i);
        } else {
            printf("Block %d already allocated. Allocation failed.\n", i);
            break;
        }
    }

    return 0;
}

