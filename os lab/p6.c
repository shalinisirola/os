#include <stdio.h>

int main() {
    // P0, P1, P2, P3, P4 are the Process names
    int n = 5; // Number of processes
    int m = 3; // Number of resources
    int i, j, k, y;

    int alloc[5][3] = { 
        {0, 1, 0},  // P0
        {2, 0, 0},  // P1
        {3, 0, 2},  // P2
        {2, 1, 1},  // P3
        {0, 0, 2}   // P4
    };

    int max[5][3] = { 
        {7, 5, 3},  // P0
        {3, 2, 2},  // P1
        {9, 0, 2},  // P2
        {2, 2, 2},  // P3
        {4, 3, 3}   // P4
    };

    int avail[3] = {3, 3, 2};  // Available Resources

    int f[n], ans[n], ind = 0;

    for (k = 0; k < n; k++) {
        f[k] = 0;  // Initialize all processes as not finished
    }

    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];  // Calculate Need matrix
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;  // Add process to safe sequence
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];  // Release allocated resources
                    }
                    f[i] = 1;  // Mark process as finished
                }
            }
        }
    }

    int isSafe = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            isSafe = 0;
            printf("The system is NOT in a safe state.\n");
            break;
        }
    }

    if (isSafe == 1) {
        printf("The system is in a SAFE state.\nSafe Sequence is: ");
        for (i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}
