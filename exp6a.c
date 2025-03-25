#include <stdio.h>
#include <stdlib.h>

void fcfs(int arr[], int n, int head) {
    int seek_count = 0;
    int distance, cur_head;

    cur_head = head;
    printf("%d -> ", cur_head);
    for (int i = 0; i < n; i++) {
        distance = abs(arr[i] - cur_head);
        seek_count += distance;
        cur_head = arr[i];
        if (i != n - 1)
            printf("%d -> ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    printf("Total Seek Time: %d\n", seek_count);
}

int main() {
    int arr[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int head = 53;

    fcfs(arr, n, head);
    return 0;
}

