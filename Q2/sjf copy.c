#include <stdio.h>

// Define a structure to hold process details
struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to sort processes by Burst Time (SJF)
void sortByBurstTime(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burst_time > p[j + 1].burst_time) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to sort processes by Process ID (for final display)
void sortById(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].id > p[j + 1].id) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n]; // Array of structures

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1; // Assign Process ID
        printf("Enter the burst time of process %d: ", p[i].id);
        scanf("%d", &p[i].burst_time);
    }

    // Sort processes by burst time (SJF Scheduling)
    sortByBurstTime(p, n);

    // First process has 0 waiting time
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;

    int total_wt = 0, total_tat = p[0].turnaround_time;

    // Compute Waiting Time & Turnaround Time
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    // Sort back the processes by Process ID
    sortById(p, n);

    // Display results
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }

    // Print averages
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turn Around Time: %.2f\n", (float)total_tat / n);

    return 0;
}
