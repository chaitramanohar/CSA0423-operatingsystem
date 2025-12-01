#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n], ct[n];
    
    printf("Enter burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // FCFS Scheduling
    wt[0] = 0;                       // first process waits 0
    ct[0] = bt[0];                   // completion time of first process
    tat[0] = ct[0];                  // turnaround = completion since arrival = 0

    for (i = 1; i < n; i++) {
        wt[i] = ct[i-1];             // waiting = previous process completion
        ct[i] = wt[i] + bt[i];       // completion time
        tat[i] = ct[i];              // turnaround = completion (arrival=0)
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i], ct[i]);
    }
    
    return 0;
}

