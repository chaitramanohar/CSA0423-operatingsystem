#include <stdio.h>

int main() {
    int pages[30], frame[10], n, f, i, j, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nOptimal Page Replacement:\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int farthest = -1, pos = 0;

            for(j = 0; j < f; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }
                if(k == n) {
                    pos = j;
                    break;
                }
            }

            frame[pos] = pages[i];
            faults++;
        }

        printf("Frames: ");
        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d", faults);
    return 0;
}

