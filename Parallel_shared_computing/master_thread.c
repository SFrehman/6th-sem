#include <stdio.h>
#include <omp.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int squares[5] = {0};

    #pragma omp parallel
    {
        // 1. Parallel work: Threads calculate squares concurrently
        #pragma omp for
        for (int i = 0; i < 5; i++) {
            squares[i] = array[i] * array[i];
        }

        // Synchronization: Ensure all squares are calculated before printing
        #pragma omp barrier

        // 2. Master section: Only thread 0 prints the intermediate results
        #pragma omp master
        {
            printf("[Thread %d] Intermediate Results (Squares):\n", omp_get_thread_num());
            for (int i = 0; i < 5; i++) {
                printf("%d squared = %d\n", array[i], squares[i]);
            }
        }

        // 3. Explicit Barrier REQUIRED here
        // Because 'omp master' has NO implicit barrier, other threads would 
        // race ahead to the next computation step before the master finishes printing.
        #pragma omp barrier

        // 4. Subsequent parallel computation continues here...
    }

    return 0;
}