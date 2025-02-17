#include <stdio.h>

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[100], at[100], bt[100], ct[100], tt[100], wt[100], rt[100];
    int i, j, temp, time = 0, completed = 0;
    float avg_wt = 0, avg_tt = 0;

    // Input for processes, burst times
    for (i = 0; i < n; i++) {
        printf("Enter the Process PID: ");
        scanf("%d", &pid[i]);
        printf("Enter the Process Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter the Process Burst time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining burst time
    }

    // Main loop for Preemptive SJF Scheduling
    while (completed < n) {
        int selected_process = -1;
        int shortest_burst_time = 10000;  // We are looking for the minimum burst time

        // Find the process with the shortest remaining burst time that is ready to run
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time && rt[i] < shortest_burst_time) {
                shortest_burst_time = rt[i];
                selected_process = i;
            }
        }

        // If we found a valid process to run
        if (selected_process != -1) {
            rt[selected_process]--;  // Decrease the remaining burst time
            time++;  // Increment the time

            // If the process has finished its burst time
            if (rt[selected_process] == 0) {
                completed++;  // Mark the process as completed
                ct[selected_process] = time;  // Completion time
                tt[selected_process] = ct[selected_process] - at[selected_process];  // Turnaround time
                wt[selected_process] = tt[selected_process] - bt[selected_process];  // Waiting time
            }
        } else {
            time++;  // If no process is available, just increment time
        }
    }

    // Calculate averages
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    avg_wt /= n;
    avg_tt /= n;

    // Output results
    printf("\nPROCESS TABLE\n");
    printf("------------------------------------------------------------\n");
    printf("| PID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("| %d   | %d            | %d          | %d              | %d               | %d            |\n",
                pid[i], at[i], bt[i], ct[i], tt[i], wt[i]);
    }
    printf("------------------------------------------------------------\n");

    // Output the averages
    printf("\nAVERAGE WAITING TIME: %.2f\n", avg_wt);
    printf("AVERAGE TURNAROUND TIME: %.2f\n", avg_tt);

    // Print Gantt Chart
    printf("\nGANTT CHART\n");
    printf("____________________________________________________________________________________ \n");
    for (i = 0; i < n; i++) {
        printf("|  %d  ", pid[i]);
    }
    printf("|\n");
    printf("____________________________________________________________________________________ \n");
    for (i = 0; i < n; i++) {
        printf("%d        ", at[i]);
    }
    printf("\n");
}
