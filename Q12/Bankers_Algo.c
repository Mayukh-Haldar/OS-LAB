#include <stdio.h>

#define MAX_PROCESSES 50
#define MAX_RESOURCES 50

int n, m;
int allocation[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES], safeSequence[MAX_PROCESSES], finish[MAX_PROCESSES] = {0};

void input() {
    int i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);
}

void calculateNeed() {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void show() {
    int i, j;
    printf("\nAllocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }
    printf("\nMax Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }
    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    printf("\nAvailable Resources:\n");
    for (i = 0; i < m; i++)
        printf("%d ", available[i]);
    printf("\n");
}

int checkSafe() {
    int work[MAX_RESOURCES], finish[MAX_PROCESSES] = {0};
    int count = 0, found;
    
    for (int i = 0; i < m; i++)
        work[i] = available[i];
    
    while (count < n) {
        found = 0;
        
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j])
                        break;
                }
                
                if (j == m) { // If all needs are satisfied
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[p][k];
                    
                    safeSequence[count++] = p;  // Use global safeSequence instead of local array
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        
        if (!found) {
            printf("System is not in a safe state!\n");
            return 0;
        }
    }
    
    printf("System is in a safe state!\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSequence[i]);  // Use the global array here as well
    printf("\n");
    return 1;
}

int main() {
    input();
    calculateNeed();
    show();
    checkSafe();
    return 0;
}
