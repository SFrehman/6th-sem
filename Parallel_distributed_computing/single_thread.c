#include <stdio.h>
#include <omp.h>

int main() {
    // Set the thread count to 4 for this demonstration
    omp_set_num_threads(4);

    printf("--- Example 1: Standard Single Construct (with implicit barrier) ---\n");
    #pragma omp parallel
    {
        // Statement 1: Only executed by ONE thread
        #pragma omp single
        {
            printf("[Thread %d] Statement 1 (Executed once)\n", omp_get_thread_num());
        } // <--- Implicit Barrier: Threads wait here until Statement 1 is printed

        // Statement 2: Executed by ALL threads in the team
        printf("[Thread %d] Statement 2 (Executed by everyone)\n", omp_get_thread_num());

        // Statement 3: Only executed by ONE thread
        #pragma omp single
        {
            printf("[Thread %d] Statement 3 (Executed once)\n", omp_get_thread_num());
        }
    }

    printf("\n--- Example 2: Single Construct with 'nowait' Clause ---\n");
    #pragma omp parallel
    {
        // Enclosed in a single block with nowait
        #pragma omp single nowait
        {
            printf("[Thread %d] Step A (Single execution, no waiting)\n", omp_get_thread_num());
        } // <--- NO Barrier: The other 3 threads skip this and instantly jump to Step B

        // Executed by all threads
        printf("[Thread %d] Step B (Executed concurrently)\n", omp_get_thread_num());
    }

    return 0;
}