#include <stdio.h>

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[100], at[100], bt[100], ct[100], tt[100], wt[100];
    int i, j, temp;
    float avg_wt = 0, avg_tt = 0;

    // Input for processes, burst times, and arrival times
    for (i = 0; i < n; i++) {
        printf("Enter the Process PID: ");
        scanf("%d", &pid[i]);
        printf("Enter the Process Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter the Process Burst Time: ");
        scanf("%d", &bt[i]); 
    }

    // Sorting processes based on arrival time (ascending order)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (at[j] > at[j + 1]) {
                // Swap Arrival Time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap PID
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // FCFS Scheduling: Calculate Completion Time, Turnaround Time, and Waiting Time
    if (at[0] > 0) {
        ct[0] = at[0] + bt[0]; // Handle idle time if first process arrives after time 0
    } else {
        ct[0] = bt[0]; // Normal case when the first process starts at time 0
    }
    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            // If the CPU is idle before the next process arrives
            ct[i] = at[i] + bt[i];
        } else {
            // Normal case where the next process starts immediately after the previous one
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i]; // Turnaround Time = Completion Time - Arrival Time
        wt[i] = tt[i] - bt[i]; // Waiting Time = Turnaround Time - Burst Time
    }

    // Calculate average waiting time and turnaround time
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    avg_wt /= n;
    avg_tt /= n;

    // Output results
    printf("\nPROCESS TABLE\n");
    printf("------------------------------------------------------------------------\n");
    printf("| PID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("| %d   | %d            | %d          | %d              | %d               | %d            |\n",
                pid[i], at[i], bt[i], ct[i], tt[i], wt[i]);
    }
    printf("------------------------------------------------------------------------\n");

    // Output the averages
    printf("\nAVERAGE WAITING TIME: %.2f\n", avg_wt);
    printf("AVERAGE TURNAROUND TIME: %.2f\n", avg_tt);

    // Print Gantt Chart
    printf("\n\t\t\t\tGANTT CHART\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    // Print process IDs in the Gantt chart
    printf("||");
    for (i = 0; i < n; i++) {
        if (i > 0 && ct[i - 1] < at[i]) {
            // Idle period in the Gantt chart
            printf("\tIDLE\t||");
        }
        printf("\tp%d\t||", pid[i]); // Print process IDs separated by ||
    }
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    // Calculate and print completion times below the || symbols
    int startTime = (at[0] > 0) ? at[0] : 0; // Adjust start time if the first process arrives after 0
    printf("  %d\t", startTime); // Print initial start time
    for (i = 0; i < n; i++) {
        if (i > 0 && ct[i - 1] < at[i]) {
            // Idle period in the Gantt chart
            startTime = at[i];
            printf("  %d\t", startTime);
        }
        int endTime = startTime + bt[i]; // Calculate end time (completion time)
        printf("  %d\t", endTime); // Print completion time without || separators
        startTime = endTime; // Update start time for the next process
    }
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
}
