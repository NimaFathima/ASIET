#include <stdio.h>
#include <string.h>

#define MAX_PROCESSES 100

// Define arrays for each attribute
int pid[MAX_PROCESSES], at[MAX_PROCESSES], bt[MAX_PROCESSES], ct[MAX_PROCESSES], tt[MAX_PROCESSES], wt[MAX_PROCESSES];
char pname[MAX_PROCESSES][10];

void getprocess(int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the %d Process PID: ", i + 1);
        scanf("%d", &pid[i]);
        printf("Enter the %d Process Name: ", i + 1);
        scanf("%s", pname[i]);
        printf("Enter the %d Process Arrival time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the %d Process Burst time: ", i + 1);
        scanf("%d", &bt[i]);
        ct[i] = 0; // Initialize completion time to zero
    }
}

void tt(int n) {
    // Calculate turnaround time: TT = CT - AT
    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i];
    }
}

void wt(int n) {
    // Calculate waiting time: WT = TT - BT
    for (int i = 0; i < n; i++) {
        wt[i] = tt[i] - bt[i];
    }
}

void print(int n) {
    // Print the details of each process
    printf("\nPID\tName\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n", pid[i], pname[i], at[i], bt[i], ct[i], tt[i], wt[i]);
    }
}

void gantt(int n) {
    int t = 0; // Time tracker for Gantt chart

    // Print the Gantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        if (t < at[i]) {
            printf("| IDLE ");
            t = at[i];
        }
        printf("| %s ", pname[i]);
        t += bt[i];
        ct[i] = t;  // Set the completion time for the current process
    }
    printf("|\n");

    // Print the process completion times directly below the Gantt chart
    printf("     ");
    for (int i = 0; i < n; i++) {
        printf("  %d  ", ct[i]);
    }
    printf("\n");
}

void sort(int n) {
    int temp_pid, temp_at, temp_bt;
    char temp_pname[10];

    // Sorting processes based on arrival time (AT)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival times
                temp_at = at[i];
                at[i] = at[j];
                at[j] = temp_at;

                // Swap burst times
                temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;

                // Swap process IDs
                temp_pid = pid[i];
                pid[i] = pid[j];
                pid[j] = temp_pid;

                // Swap process names
                strcpy(temp_pname, pname[i]);
                strcpy(pname[i], pname[j]);
                strcpy(pname[j], temp_pname);
            }
        }
    }
}

void complete(int n) {
    int t = 0; // Initial time

    // Calculate the completion times for the processes
    for (int i = 0; i < n; i++) {
        if (t < at[i]) {
            t = at[i];  // If CPU is idle, jump to the next process arrival time
        }
        t += bt[i]; // Process burst time
        ct[i] = t;  // Store the completion time for the current process
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    getprocess(n);
    sort(n);
    complete(n);
    tt(n);
    wt(n);
    print(n);
    gantt(n);

    return 0;
}
