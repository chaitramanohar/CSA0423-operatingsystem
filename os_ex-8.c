#include <stdio.h>

int main() {
    int n, i, j, time = 0, tq, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], remaining[n], waiting[n], turnaround[n], process[n];

    for(i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter burst time for process P%d: ", i+1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        waiting[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nGantt Chart (Time -> Process ID):\n");

    while(done < n) {
        int all_done = 1;
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0) {
                all_done = 0;
                if(remaining[i] > tq) {
                    printf("%d -> P%d ", time, process[i]);
                    time += tq;
                    remaining[i] -= tq;
                } else {
                    printf("%d -> P%d ", time, process[i]);
                    time += remaining[i];
                    waiting[i] = time - burst[i];
                    remaining[i] = 0;
                    done++;
                }
            }
        }
        if(all_done) break;
    }
    printf("%d\n", time);

    // Calculate Turnaround Time
    for(i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", process[i], burst[i], waiting[i], turnaround[i]);
    }

    // Average waiting and turnaround time
    float avg_wait = 0, avg_turnaround = 0;
    for(i = 0; i < n; i++) {
        avg_wait += waiting[i];
        avg_turnaround += turnaround[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround / n);

    return 0;
}

