#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, disk;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], i, j, temp;
    printf("Enter request queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &disk);

    // Sort
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    int total = 0, pos = 0;

    for (i = 0; i < n; i++)
        if (req[i] > head) { pos = i; break; }

    printf("\nC-SCAN ORDER:\n%d", head);

    // Move right
    for (i = pos; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    // Move to end
    total += abs((disk - 1) - head);
    head = disk - 1;
    printf(" -> %d", head);

    // Jump to beginning
    total += abs((disk - 1) - 0);
    head = 0;
    printf(" -> %d", head);

    // Continue from start
    for (i = 0; i < pos; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}

