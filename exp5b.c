#include <stdio.h>

int main() {
    int incomingstream[] = {4, 1, 2, 4, 5};  // Incoming page stream
    int pageFaults = 0;
    int frames = 3;  // Number of frames
    int m, n, s, pages;
    pages = sizeof(incomingstream) / sizeof(incomingstream[0]);

    // Printing header
    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");

    int temp[frames];  // Array to store frames
    int lastUsed[frames];  // Array to store the last used times of pages in frames
    for (m = 0; m < frames; m++) {
        temp[m] = -1;  // Initialize all frames to -1 (empty)
        lastUsed[m] = -1;  // Initialize last used array to -1 (no page used yet)
    }

    int next = 0;  // Next frame index to be replaced

    for (m = 0; m < pages; m++) {
        s = 0;  // Flag to check if the page is already in a frame

        // Check if the page is already in one of the frames
        for (n = 0; n < frames; n++) {
            if (incomingstream[m] == temp[n]) {
                s = 1;  // Page is found in the frames
                lastUsed[n] = m;  // Update the last used time of this page
                break;
            }
        }

        if (s == 0) {  // Page not found, page fault occurs
            // Find the least recently used page (one with the smallest lastUsed value)
            int lruIndex = 0;
            for (n = 1; n < frames; n++) {
                if (lastUsed[n] < lastUsed[lruIndex]) {
                    lruIndex = n;
                }
            }

            // Replace the LRU page with the new page
            temp[lruIndex] = incomingstream[m];
            lastUsed[lruIndex] = m;  // Set the last used time of the new page
            pageFaults++;  // Increment page fault count
        }

        // Print the current state of the frames
        printf("%d\t\t", incomingstream[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1) {
                printf("%d\t\t", temp[n]);
            } else {
                printf("-\t\t");
            }
        }
        printf("\n");
    }

    // Print total page faults
    printf("Total page Faults: \t%d\n", pageFaults);

    return 0;
}

