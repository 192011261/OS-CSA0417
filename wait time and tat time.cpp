#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int n;                         
    int burst_times[MAX_PROCESSES]; 
    int waiting_times[MAX_PROCESSES]; 
    int turnaround_times[MAX_PROCESSES]; 
    int i, j, temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the CPU burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_times[i]);
    }

    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (burst_times[j] < burst_times[min_idx]) {
                min_idx = j;
            }
        }
        temp = burst_times[i];
        burst_times[i] = burst_times[min_idx];
        burst_times[min_idx] = temp;
    }

    waiting_times[0] = 0;
    turnaround_times[0] = burst_times[0];
    for (i = 1; i < n; i++) {
        waiting_times[i] = waiting_times[i-1] + burst_times[i-1];
        turnaround_times[i] = turnaround_times[i-1] + burst_times[i];
    }

    float avg_waiting_time = 0.0;
    float avg_turnaround_time = 0.0;
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_times[i];
        avg_turnaround_time += turnaround_times[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
