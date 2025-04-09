#include<stdio.h>
#include<stdlib.h>

void main() {
    int queue[100], n, head, max_cylinder, direction, temp, seek = 0;
    int i, j, left[50], right[50], left_count = 0, right_count = 0;
    float avg_seek_time;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    printf("Enter the disk request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    printf("Enter the maximum cylinder number: ");
    scanf("%d", &max_cylinder);
    
    printf("Enter the direction (1 for high, 0 for low): ");
    scanf("%d", &direction);
    
    // Divide requests into left and right sides of the head
    for(i = 0; i < n; i++) {
        if(queue[i] < head)
            left[left_count++] = queue[i];
        else if(queue[i] > head)
            right[right_count++] = queue[i];
    }
    
    // Sort left array in descending order
    for(i = 0; i < left_count - 1; i++) {
        for(j = 0; j < left_count - i - 1; j++) {
            if(left[j] < left[j+1]) {
                temp = left[j];
                left[j] = left[j+1];
                left[j+1] = temp;
            }
        }
    }
    
    // Sort right array in ascending order
    for(i = 0; i < right_count - 1; i++) {
        for(j = 0; j < right_count - i - 1; j++) {
            if(right[j] > right[j+1]) {
                temp = right[j];
                right[j] = right[j+1];
                right[j+1] = temp;
            }
        }
    }
    
    printf("\nSCAN Disk Scheduling Algorithm\n");
    printf("Order of head movements: %d", head);
    
    // Process based on direction
    if(direction == 1) {  // Moving toward higher cylinder
        for(i = 0; i < right_count; i++) {
            printf(" -> %d", right[i]);
            seek += abs(head - right[i]);
            head = right[i];
        }
        
        // After reaching the end, move to the beginning
        if(right_count != 0) {
            printf(" -> %d", max_cylinder);
            seek += abs(head - max_cylinder);
            head = max_cylinder;
        }
        
        for(i = 0; i < left_count; i++) {
            printf(" -> %d", left[i]);
            seek += abs(head - left[i]);
            head = left[i];
        }
    } 
    else {  // Moving toward lower cylinder
        for(i = 0; i < left_count; i++) {
            printf(" -> %d", left[i]);
            seek += abs(head - left[i]);
            head = left[i];
        }
        
        // After reaching the beginning, move to the end
        if(left_count != 0) {
            printf(" -> 0");
            seek += abs(head - 0);
            head = 0;
        }
        
        for(i = 0; i < right_count; i++) {
            printf(" -> %d", right[i]);
            seek += abs(head - right[i]);
            head = right[i];
        }
    }
    
    avg_seek_time = (float)seek / n;
    
    printf("\nTotal seek time: %d", seek);
    printf("\nAverage seek time: %.2f\n", avg_seek_time);
}
