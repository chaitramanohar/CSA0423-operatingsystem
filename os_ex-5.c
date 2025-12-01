#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], priority[n], waiting[n], turnaround[n], process[n];

    for(i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter burst time for process P%d: ", i+1);
        scanf("%d", &burst[i]);
        printf("Enter priority for process P%d (lower number = higher priority): ", i+1);
        scanf("%d", &priority[i]);
    }

    // Sort processes based on priority (lower number = higher priority)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(priority[i] > priority[j]) {
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
                temp = process[i]; process[i] = process[j]; process[j] = temp;
            }
        }
    }

    // Calculate waiting time
    waiting[0] = 0;
    for(i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process[i], burst[i], priority[i], waiting[i], turnaround[i]);
    }

    // Calculate and display average times
    float total_wait = 0, total_turnaround = 0;
    for(i = 0; i < n; i++) {
        total_wait += waiting[i];
        total_turnaround += turnaround[i];
    }
    printf("\nAverage Waiting Time: %.2f", total_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);

    return 0;
}

