#include <stdio.h>
#include <stdlib.h>

void main() {
    int q[100], n, seek = 0, i, cur, prev, j, m, cyl, loc;
    float avg;

    printf("Enter the number of Cylinders: ");
    scanf("%d", &cyl);
    printf("Cylinders: 0 to %d\n", cyl - 1);

    printf("Enter the Queue Size: ");
    scanf("%d", &m);

    n = m + 1;
    printf("Enter the Queue: ");
    for (i = 1; i < n; i++) {
        scanf("%d", &q[i]);
    }

    printf("Enter Current Head Position: ");
    scanf("%d", &cur);
    q[0] = cur;

    printf("Enter Previous Head Position: ");
    scanf("%d", &prev);

    // Sorting the request queue
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (q[j] > q[j + 1]) {
                int temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }

    printf("Displaying Requests in Order...\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", q[i]);
    }

    // Find the current head's location in the sorted queue
    for (i = 0; i < n; i++) {
        if (q[i] == cur) {
            loc = i;
            break;
        }
    }

    if (cur < prev) {
        printf("\n\nScanning towards left...then right\n");

        // Scan towards left first
        for (i = loc; i >= 0; i--) {
            printf("%d --> ", q[i]);
        }
        printf("0 --> ");
        
        // Scan towards right after reaching 0
        for (i = loc + 1; i < n; i++) {
            printf("%d --> ", q[i]);
        }
        
        seek = cur + q[n - 1]; // Total seek distance
    } else {
        printf("\n\nScanning towards right...then left\n");

        // Scan towards right first
        for (i = loc; i < n; i++) {
            printf("%d --> ", q[i]);
        }
        printf("%d --> ", cyl - 1);

        // Scan towards left after reaching the farthest right
        for (i = loc - 1; i >= 0; i--) {
            printf("%d --> ", q[i]);
        }

        seek = 2 * (cyl - 1) - cur - q[0]; // Total seek distance
    }

    printf("\n\nTotal Seek Distance: %d\t", seek);
    avg = (float)seek / n;
    printf("\nAverage Seek Distance: %.3f\t", avg);
}
