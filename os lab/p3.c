#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg = 0, tatavg = 0;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get burst times for each process
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }

    // Waiting time for the first process is 0
    wt[0] = 0;
    tat[0] = bt[0];

    // Calculate waiting and turnaround times
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Calculate total waiting time and turnaround time
    for (i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Print results
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}

./p3
Enter the number of processes: 3
Enter Burst Time for Process 0: 24
Enter Burst Time for Process 1: 3
Enter Burst Time for Process 2: 3

        PROCESS BURST TIME      WAITING TIME    TURNAROUND TIME
        P0              24              0               24
        P1              3               24              27
        P2              3               27              30

Average Waiting Time: 17.00
Average Turnaround Time: 27.00