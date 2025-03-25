#include <stdio.h>
#include <stdlib.h>

void scan(int req[], int n, int head, int dir, int size) {
    int seek = 0, seq[n+2], idx = 0, i, j;
    int left[n], right[n], l = 0, r = 0;
    
    // Split requests
    for (i = 0; i < n; i++)
        req[i] < head ? left[l++] = req[i] : (right[r++] = req[i]);
    
    // Sort left (desc) and right (asc)
    for (i = 0; i < l-1; i++)
        for (j = 0; j < l-i-1; j++)
            if (left[j] < left[j+1])
                left[j] ^= left[j+1] ^= left[j] ^= left[j+1];
    
    for (i = 0; i < r-1; i++)
        for (j = 0; j < r-i-1; j++)
            if (right[j] > right[j+1])
                right[j] ^= right[j+1] ^= right[j] ^= right[j+1];
    
    // Add boundary if needed
    if (!dir) left[l++] = 0;
    else right[r++] = size-1;
    
    // Build sequence
    seq[idx++] = head;
    for (i = 0; i < l; i++) {
        seek += abs(left[i] - seq[idx-1]);
        seq[idx++] = left[i];
    }
    for (i = 0; i < r; i++) {
        seek += abs(right[i] - seq[idx-1]);
        seq[idx++] = right[i];
    }
    
    // Print results
    printf("SCAN Order:\n%d", seq[0]);
    for (i = 1; i < idx; i++) printf(" -> %d", seq[i]);
    printf("\nTotal Seek: %d\n", seek);
}

int main() {
    int req[] = {98, 183, 41, 122, 14, 124, 65, 67};
    scan(req, sizeof(req)/sizeof(req[0]), 53, 0, 200);
    return 0;
}
