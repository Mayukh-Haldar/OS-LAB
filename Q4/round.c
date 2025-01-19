#include <stdio.h>

// Define a structure to hold process details
struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

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
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n]; // Array of structures

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1; // Assign Process ID
        printf("Enter the burst time of process %d: ", p[i].id);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int total_time = 0, completed = 0;
    
    // Round Robin Execution
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                if (p[i].remaining_time > tq) {
                    total_time += tq;
                    p[i].remaining_time -= tq;
                } else {
                    total_time += p[i].remaining_time;
                    p[i].turnaround_time = total_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    p[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }

    // Sort back the processes by Process ID
    sortById(p, n);

    // Display results
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }

    // Calculate and print averages
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turn Around Time: %.2f\n", total_tat / n);

    return 0;
}
