#include <stdio.h>

int main() {
    int pages[30], frame[10], n, f, i, j, faults = 0, counter = 0;
    int time[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                time[j] = ++counter;
                break;
            }
        }

        if(!found) {
            int minTime = 9999, pos = 0;
            for(j = 0; j < f; j++) {
                if(time[j] < minTime) {
                    minTime = time[j];
                    pos = j;
                }
            }
            frame[pos] = pages[i];
            time[pos] = ++counter;
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

