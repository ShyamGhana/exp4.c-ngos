#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sstf(int arr[], int n, int head) {
    int seek_count = 0;
    int visited[n];
    int cur_head = head;
    
    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("%d -> ", cur_head);
    
    for (int i = 0; i < n; i++) {
        int min_distance = INT_MAX;
        int next_index = -1;
        
        // Find the nearest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(arr[j] - cur_head);
                if (distance < min_distance) {
                    min_distance = distance;
                    next_index = j;
                }
            }
        }
        
        if (next_index == -1) break;  // All requests processed
        
        visited[next_index] = 1;
        seek_count += min_distance;
        cur_head = arr[next_index];
        
        if (i != n - 1)
            printf("%d -> ", cur_head);
        else
            printf("%d\n", cur_head);
    }
    
    printf("Total Seek Time: %d\n", seek_count);
}

int main() {
    int arr[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int head = 53;

    sstf(arr, n, head);
    return 0;
}
