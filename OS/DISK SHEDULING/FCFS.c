#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, q[100], i, diff, seek = 0;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);

    printf("Enter the Queue: ");
    for(i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &q[0]);

    for(i = 0; i < n; i++) {
        diff = abs(q[i] - q[i + 1]);
        seek += diff;
        printf("\nMove from %d to %d and the seek is %d", q[i], q[i + 1], diff);
    }

    printf("\n\nTotal Seek Distance is: %d", seek);

    float avg = (float)seek / n;
    printf("\nAverage Seek Distance is: %.3f", avg);
}
