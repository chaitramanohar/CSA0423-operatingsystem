#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int priority;
    int waiting;
    int turnaround;
} Process;

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("Enter arrival time for process P%d: ", i+1);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for process P%d: ", i+1);
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;
        printf("Enter priority for process P%d (lower number = higher priority): ", i+1);
        scanf("%d", &p[i].priority);
    }

    int prev = -1;
    printf("\nGantt Chart (Time -> Process ID):\n");
    while(completed < n) {
        int idx = -1;
        int highestPriority = INT_MAX;

        for(i = 0; i < n; i++) {
            if(p[i].arrival <= time && p[i].remaining > 0 && p[i].priority < highestPriority) {
                highestPriority = p[i].priority;
                idx = i;
            }
        }

        if(idx != -1) {
            if(prev != idx) printf("%d -> P%d ", time, p[idx].pid);
            p[idx].remaining--;
            time++;
            prev = idx;

            if(p[idx].remaining == 0) {
                p[idx].turnaround = time - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                completed++;
            }
        } else {
            time++; // idle CPU
        }
    }
    printf("%d\n", time);

    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority, p[i].waiting, p[i].turnaround);
    }

    float avg_wait = 0, avg_turnaround = 0;
    for(i = 0; i < n; i++) {
        avg_wait += p[i].waiting;
        avg_turnaround += p[i].turnaround;
    }
    printf("\nAverage Waiting Time: %.2f", avg_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround / n);

    return 0;
}

