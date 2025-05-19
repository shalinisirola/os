#include <stdio.h>
int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;
    
    printf("Enter the number of processes -- ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];  // Copy burst times to ct for later use
    }
    
    printf("\nEnter the size of time slice -- ");
    scanf("%d", &t);
    
    max = bu[0];  // Set max to the first process's burst time initially
    for(i = 1; i < n; i++) {
        if(max < bu[i]) {
            max = bu[i];
        }
    }

    // Round Robin scheduling simulation
    for(j = 0; j < (max + t - 1) / t; j++) {  // Loop until all processes are completed
        for(i = 0; i < n; i++) {
            if(bu[i] > 0) {  // Process not completed
                if(bu[i] <= t) {
                    tat[i] = temp + bu[i];  // Turnaround time
                    temp += bu[i];          // Increment temp with burst time
                    bu[i] = 0;              // Process completed
                } else {
                    bu[i] -= t;            // Deduct time slice
                    temp += t;             // Increment temp with time slice
                }
            }
        }
    }

    // Calculating waiting time and turnaround time
    for(i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];  // Waiting time = Turnaround time - Burst time
        att += tat[i];            // Accumulate total turnaround time
        awt += wa[i];             // Accumulate total waiting time
    }
    
    printf("\nThe Average Turnaround time is -- %.2f", att / n);
    printf("\nThe Average Waiting time is -- %.2f", awt / n);
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");
    
    for(i = 0; i < n; i++) {
        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
    }
    
    return 0;
}
