#include <stdio.h>
#include <omp.h>

#define MAX 10

int main() {
    int count = 0;

    // Parallel region creating 10 threads
    #pragma omp parallel num_threads(MAX)
    {
        // Atomically increment count to avoid race conditions
        #pragma omp atomic update
        count++; 
    }

    // Output will consistently be 10
    printf("Final Count: %d\n", count);
    return 0;
}