#include <stdio.h>

void bestFit(int blocks[], int blockSize, int processes[], int processSize) {
    int allocated[processSize]; 
    int occupied[blockSize];

    for (int i = 0; i < processSize; i++) { 
        allocated[i] = -1; 
    } 

    for (int i = 0; i < blockSize; i++) { 
        occupied[i] = 0; 
    }

    for (int i = 0; i < processSize; i++) { 
        int bestIndex = -1; 
        for (int j = 0; j < blockSize; j++) {
            if (blocks[j] >= processes[i] && !occupied[j]) {
                if (bestIndex == -1) 
                    bestIndex = j; 
                else if (blocks[j] < blocks[bestIndex]) 
                    bestIndex = j; 
            }
        }

        if (bestIndex != -1) { 
            allocated[i] = bestIndex; 
            occupied[bestIndex] = 1; 
        } 
    } 

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processSize; i++) { 
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocated[i] != -1) 
            printf("%d\n", allocated[i] + 1); 
        else 
            printf("Not Allocated\n"); 
    }
}

int main() { 
    int blocks[] = {100, 50, 30, 120, 35};
    int processes[] = {40, 10, 30, 60};
    int blockSize = sizeof(blocks) / sizeof(blocks[0]);
    int processSize = sizeof(processes) / sizeof(processes[0]);

    bestFit(blocks, blockSize, processes, processSize);

    return 0; 
}
