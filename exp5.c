#include<stdio.h>
int main()
{
    int incomingstream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    pages = sizeof(incomingstream) / sizeof(incomingstream[0]);

    // Printing header
    printf("incoming\tFrame 1\tFrame 2\tFrame 3\n");

    int temp[frames];
    for (m = 0; m < frames; m++) {
        temp[m] = -1; 
    }

    int next = 0; 
    for (m = 0; m < pages; m++) {
        s = 0;  

        
        for (n = 0; n < frames; n++) {
            if (incomingstream[m] == temp[n]) {
                s = 1;  
                break;
            }
        }

        if (s == 0) {  
            
            temp[next] = incomingstream[m];
            next = (next + 1) % frames;  
            pageFaults++;  
        }

       
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

  
    printf("Total page Faults: \t%d\n", pageFaults);

    return 0;
}

