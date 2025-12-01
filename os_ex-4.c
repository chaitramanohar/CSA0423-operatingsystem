#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], wt[n], tat[n], ct[n];

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;   // process IDs
    }

    // Sort processes according to burst time (Simple selection sort)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process ID
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // First process
    wt[0] = 0;
    ct[0] = bt[0];
    tat[0] = ct[0];

    // Remaining
    for (i = 1; i < n; i++) {
        wt[i] = ct[i - 1];
        ct[i] = wt[i] + bt[i];
        tat[i] = ct[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i], ct[i]);
    }

    return 0;
}

