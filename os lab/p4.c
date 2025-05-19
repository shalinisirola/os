#include <stdio.h>

int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;

    // Input number of processes
    printf("Enter the number of processes -- ");
    scanf("%d", &n);

    // Input burst times
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d -- ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];  // Copy of original burst time for final output
    }

    // Input time quantum
    printf("Enter the size of time slice -- ");
    scanf("%d", &t);

    // Find maximum burst time (used to determine number of loops needed)
    max = bu[0];
    for (i = 1; i < n; i++) {
        if (max < bu[i]) {
            max = bu[i];
        }
    }

    // Round Robin Scheduling Logic
    int done;
    do {
        done = 1; // Assume all processes are done
        for (i = 0; i < n; i++) {
            if (bu[i] > 0) {
                done = 0; // At least one process is not done

                if (bu[i] <= t) {
                    temp += bu[i];
                    tat[i] = temp; // Completion time becomes turnaround time
                    bu[i] = 0;
                } else {
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    } while (!done);

    // Calculate waiting time and averages
    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];  // Waiting = Turnaround - Burst
        att += tat[i];
        awt += wa[i];
    }

    // Display results
    
    printf("\n\n\tPROCESS\t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");

    for (i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
    }
    

    return 0;
}

Enter the number of processes: 3
Enter Burst Time for process 1: 24
Enter Burst Time for process 2: 3
Enter Burst Time for process 3: 3
Enter the size of time slice: 3

PROCESS BURST TIME WAITING TIME TURNAROUND TIME
1       24         6            30
2       3          4            7
3       3          7            10

The Average Turnaround time is – 15.666667
The Average Waiting time is------- 5.666667
