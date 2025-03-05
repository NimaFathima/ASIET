#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    int id;                   // Variable to store shared memory ID
    void *sm;                 // Pointer to the shared memory
    char buf[100];            // Buffer to store the data read from shared memory

    // Access the shared memory segment with key 1222
    id = shmget((key_t)1222, 1024, 0666);
    printf("Key of Shared Memory is %d\n", id);

    // Attach the process to the shared memory
    sm = shmat(id, NULL, 0);
    printf("Process attached at %p\n", sm);

    // Read and print the data from the shared memory
    printf("Data read from Memory:\n%s\n", (char *)sm);

    // Copy the data from shared memory to a buffer
    strcpy(buf, sm);

    // Extract numerical values from the buffer and compute their sum
    int a = buf[0] - '0';   // Convert the first character to an integer
    int b = buf[2] - '0';   // Convert the third character to an integer
    printf("The Sum is %d\n", a + b);
}
