#include <stdio.h>

void main() {
    int p[100], at[100], bt[100], priority[100], n, ct[100], wt[100], tt[100];
    float avg_tt = 0, avg_wt = 0;

    // Input number of processes
    printf("ENTER THE NO OF PROCESS : ");
    scanf("%d", &n);

    // Input process details: arrival time, burst time, and priority
    printf("ENTER THE PROCESS DETAILS\n");
    for (int i = 0; i < n; i++) {
        printf("ENTER FOR PROCESS p%d\n", i + 1);
        printf("at : ");
        scanf("%d", &at[i]);
        printf("bt : ");
        scanf("%d", &bt[i]);
        printf("priority : ");
        scanf("%d", &priority[i]);
        p[i] = i + 1;
    }

    // Sort processes based on priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priorities
                int temp_priority = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp_priority;

                // Swap burst times
                int temp_bt = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp_bt;

                // Swap process IDs
                int temp_p = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp_p;

                // Swap arrival times
                int temp_at = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp_at;
            }
        }
    }

    // Calculate completion time, waiting time, and turnaround time
    int currentTime = 0; // Initialize current time to 0
    for (int i = 0; i < n; i++) {
        // Introduce idle time if there's a gap between current time and arrival time
        if (currentTime < at[i]) {
            currentTime = at[i]; // Adjust current time to the arrival time
        }

        ct[i] = currentTime + bt[i]; // Calculate completion time
        wt[i] = currentTime - at[i]; // Calculate waiting time
        tt[i] = ct[i] - at[i];       // Calculate turnaround time
        currentTime = ct[i];         // Update current time

        avg_wt += wt[i];
        avg_tt += tt[i];
    }
    avg_wt /= n;
    avg_tt /= n;

    // Print average TT and WT
    printf("AVERAGE TT = %.6f\n", avg_tt);
    printf("AVERAGE WT = %.6f\n", avg_wt);

    // Print process details
    printf("\n----------------------------------------\n");
    printf("PID\tAT\tBT\tPRIORITY\tCT\tWT\tTT\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], priority[i], ct[i], wt[i], tt[i]);
    }
    printf("----------------------------------------\n");

    // Print Gantt Chart
    printf("\n\t\t\t\tGANTT CHART\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    // Print process IDs in the Gantt chart
    printf("||");
    for (int i = 0; i < n; i++) {
        printf("\tp%d\t||", p[i]);
    }
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    // Calculate and print completion times below the || symbols
    int startTime = 0;
    printf("  %d\t", startTime);
    for (int i = 0; i < n; i++) {
        int endTime = startTime + bt[i];
        if (startTime < at[i]) { // Include idle time in the Gantt chart
            printf("  %d\t", at[i]);
            startTime = at[i];
        }
        endTime = startTime + bt[i];
        printf("  %d\t", endTime);
        startTime = endTime;
    }
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
}
