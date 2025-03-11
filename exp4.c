#include <stdio.h>

int main() {
    int P = 5;  // Number of processes
    int R = 3;  // Number of resource types

    // Maximum resource needs for each process
    int max[5][3] = {
        {7, 5, 3},  // Max needs for P0
        {3, 2, 2},  // Max needs for P1
        {9, 0, 2},  // Max needs for P2
        {2, 2, 2},  // Max needs for P3
        {4, 3, 3}   // Max needs for P4
    };

    // Resources already allocated to each process
    int alloc[5][3] = {
        {0, 1, 0},  // Allocated to P0
        {2, 0, 0},  // Allocated to P1
        {3, 0, 2},  // Allocated to P2
        {2, 1, 1},  // Allocated to P3
        {0, 0, 2}   // Allocated to P4
    };

    // Available resources in the system
    int avail[3] = {3, 3, 2};

    // Need matrix (Max - Alloc)
    int need[5][3];

    // Calculate Need matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Display Max, Alloc, and Avail matrices
    printf("Max Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAlloc Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for (int j = 0; j < R; j++) {
        printf("%d ", avail[j]);
    }
    printf("\n");

    // Display Need matrix
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Safe sequence finding using Banker's Algorithm
    int finish[5] = {0};  // All processes are initially not finished
    int work[3];
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int safeSeq[5];  // To store the safe sequence
    int count = 0;   // Number of processes that can finish

    while (count < P) {
        int found = 0;  // To check if we find a process that can finish

        // Find a process whose need can be satisfied with available resources
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {  // If process is not finished
                int canFinish = 1;
                // Check if Need <= Work
                for (int j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        canFinish = 0;
                        break;
                    }
                }
                // If process can finish
                if (canFinish == 1) {
                    for (int j = 0; j < R; j++) {
                        work[j] += alloc[p][j];  // Release resources
                    }
                    finish[p] = 1;  // Mark process as finished
                    safeSeq[count++] = p;  // Add process to safe sequence
                    found = 1;
                    break;
                }
            }
        }

        if (found == 0) {  // If no process can finish, system is unsafe
            printf("\nSystem is in an unsafe state!\n");
            return 0;
        }
    }

    // Print the safe sequence
    printf("\nSystem is in a safe state.\n");
    printf("Safe sequence: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}

