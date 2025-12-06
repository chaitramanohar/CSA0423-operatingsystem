#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request queue: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total = 0;
    printf("\nFCFS ORDER:\n%d", head);

    for (i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}

