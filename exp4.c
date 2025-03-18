#include <stdio.h>

int main() {
    int P = 5;  
    int R = 3; 

  
    int max[5][3] = {
        {7, 5, 3},  
        {3, 2, 2},  
        {9, 0, 2}, 
        {2, 2, 2},  
        {4, 3, 3}  
    };

   
    int alloc[5][3] = {
        {0, 1, 0}, 
        {2, 0, 0},  
        {3, 0, 2}, 
        {2, 1, 1},  
        {0, 0, 2}   
    };
   

    int avail[3] = {3, 3, 2};

  
    int need[5][3];

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

 
    printf("Max :\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAlloc :\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable : ");
    for (int j = 0; j < R; j++) {
        printf("%d ", avail[j]);
    }
    printf("\n");

   
    printf("\nNeed :\n");
    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    
    int finish[5] = {0};  
    int work[3];
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int safeSeq[5];  
    int count = 0;

    while (count < P) {
        int found = 0; 

        
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {  
                int canFinish = 1;
               
                for (int j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        canFinish = 0;
                        break;
                    }
                }
               
                if (canFinish == 1) {
                    for (int j = 0; j < R; j++) {
                        work[j] += alloc[p][j];  
                    }
                    finish[p] = 1;  
                    safeSeq[count++] = p;  
                    found = 1;
                    break;
                }
            }
        }

        if (found == 0) {  
            printf("\nunsafe state!\n");
            return 0;
        }
    }

  
    printf("\nsafe state.\n");
    printf("Safe sequence: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}

