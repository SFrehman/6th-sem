#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int array[10];
    
    // Create an array of 10 random numbers
    for(int i = 0; i < 10; i++) {
        array[i] = rand() % 100; // Random number between 0 and 99
        printf("%d ", array[i]);
    }
    printf("\n");

    int max = array[0]; // Store the first element in max

    // Specify the parallel region
    #pragma omp parallel
    {
        // Thread-local variables or loop logic
        #pragma omp for
        for(int i = 0; i < 10; i++) {
            // Critical section ensures only one thread executes this comparison at a time
            #pragma omp critical
            {
                if(array[i] > max) {
                    max = array[i];
                }
            }
        }
    }

    printf("The largest number is: %d\n", max);
    return 0;
}