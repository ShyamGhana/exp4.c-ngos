#include <stdio.h>
#include <stdlib.h>

void cscan(int requests[], int n, int head, int disk_size) {
    int left[n], right[n];
    int left_size = 0, right_size = 0;
    
    // 1. Split requests into left and right of head
    for (int i = 0; i < n; i++) {
        if (requests[i] <= head)
            left[left_size++] = requests[i]; // Left side (≤ head)
        else
            right[right_size++] = requests[i]; // Right side (> head)
    }
    
    // 2. Sort left (descending) and right (ascending)
    // Simple bubble sort for left (big to small)
    for (int i = 0; i < left_size - 1; i++) {
        for (int j = 0; j < left_size - i - 1; j++) {
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }
    
    // Simple bubble sort for right (small to big)
    for (int i = 0; i < right_size - 1; i++) {
        for (int j = 0; j < right_size - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }
    
    // 3. Add disk boundaries (jump from end to start)
    right[right_size++] = disk_size - 1; // Go to end (199)
    left[left_size++] = 0; // Then jump to start (0)
    
    // 4. Calculate seek sequence
    int seek_count = 0;
    printf("C-SCAN Order:\n%d", head);
    
    // Move right (upwards)
    for (int i = 0; i < right_size; i++) {
        seek_count += abs(right[i] - head);
        head = right[i];
        printf(" → %d", head);
    }
    
    // Move left (from 0 upwards)
    for (int i = 0; i < left_size; i++) {
        seek_count += abs(left[i] - head);
        head = left[i];
        printf(" → %d", head);
    }
    
    printf("\nTotal Seek Time = %d\n", seek_count);
}

int main() {
    int requests[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53;
    int disk_size = 200;
    
    cscan(requests, n, head, disk_size);
    return 0;
}
