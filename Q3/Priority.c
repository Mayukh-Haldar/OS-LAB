#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct process_struct {
    int pid;     // Process ID
    int at;      // Arrival time
    int bt;      // Burst time
    int priority; // Priority (lower number means higher priority)
    int ct, wt, tat, rt, start_time;
} ps[100];

int findmax(int a, int b) {
    return a > b ? a : b;
}

int findmin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    bool is_completed[100] = {false};
    int current_time = 0;
    int completed = 0;
    int total_idle_time = 0, prev = 0, length_cycle;
    float cpu_utilization;
    int max_completion_time = INT_MIN, min_arrival_time = INT_MAX;

    // Prompt user for number of processes
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i);
        ps[i].pid = i;  // Assign Process ID
        scanf("%d", &ps[i].at);  // Arrival time
    }
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &ps[i].bt);  // Burst time
    }
    for (int i = 0; i < n; i++) {
        printf("Enter Priority for Process %d (lower number means higher priority): ", i);
        scanf("%d", &ps[i].priority);  // Priority
    }

    // Scheduling processes
    while (completed != n) {
        // Find process with min priority that is ready to execute at the current time
        int max_index = -1;
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (ps[i].at <= current_time && !is_completed[i]) {
                // Check for lowest priority (min priority number) and resolve ties by arrival time
                if (ps[i].priority < minimum) {
                    minimum = ps[i].priority;
                    max_index = i;
                }
                if (ps[i].priority == minimum && ps[i].at < ps[max_index].at) {
                    minimum = ps[i].priority;
                    max_index = i;
                }
            }
        }

        if (max_index == -1) {
            current_time++;  // If no process is ready, increment time
        } else {
            // Process is selected to execute
            ps[max_index].start_time = current_time;
            ps[max_index].ct = ps[max_index].start_time + ps[max_index].bt;
            ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
            ps[max_index].wt = ps[max_index].tat - ps[max_index].bt;
            ps[max_index].rt = ps[max_index].start_time - ps[max_index].at;

            // Update totals
            sum_tat += ps[max_index].tat;
            sum_wt += ps[max_index].wt;
            sum_rt += ps[max_index].rt;

            // Handle idle time (if this is not the first process)
            total_idle_time += (current_time == 0) ? 0 : (ps[max_index].start_time - prev);

            // Mark process as completed
            completed++;
            is_completed[max_index] = true;
            current_time = ps[max_index].ct;  // Update the current time
            prev = current_time;  // Set prev as current time for idle time calculation
        }
    }

    // Calculate the length of the process completion cycle
    for (int i = 0; i < n; i++) {
        max_completion_time = findmax(max_completion_time, ps[i].ct);
        min_arrival_time = findmin(min_arrival_time, ps[i].at);
    }
    length_cycle = max_completion_time - min_arrival_time;
    cpu_utilization = (float)(length_cycle - total_idle_time) / length_cycle;

    // Output the results in table format
    printf("\nProcess ID | AT | BT | Priority | CT | TAT | WT | RT\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("    %d     | %d  | %d  |    %d   |  %d  |  %d  | %d  | %d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].priority, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    }

    // Average Turnaround Time, Waiting Time, Response Time
    printf("\nAverage Turnaround Time: %f\n", sum_tat / n);
    printf("Average Waiting Time: %f\n", sum_wt / n);
    printf("Average Response Time: %f\n", sum_rt / n);

    // Throughput and CPU Utilization
    printf("Throughput: %f\n", n / (float)length_cycle);
    printf("CPU Utilization (Percentage): %f%%\n", cpu_utilization * 100);

    return 0;
}
