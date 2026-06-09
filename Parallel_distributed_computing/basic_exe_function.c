#include <stdio.h>
#include <omp.h>

int main() {
    // 1. OMP IN PARALLEL: Returns 0 outside parallel blocks [00:03:01]
    printf("Outside parallel region: omp_in_parallel() = %d\n", omp_in_parallel());

    // 2. OMP GET NUM PROCS: Returns hardware CPU processor count [00:03:35]
    printf("Number of available processors: %d\n", omp_get_num_procs());

    // Set thread count to 4 for the parallel region
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        // 3. Gets the private unique ID of the current thread (starts at 0) [00:00:31, 00:01:03]
        int id = omp_get_thread_num();

        // 4. Gets total number of active threads in the current team [00:00:41]
        int total_threads = omp_get_num_threads();

        // 5. Returns 1 (nonzero) inside parallel blocks [00:03:13]
        if (id == 0) {
            printf("Inside parallel region: omp_in_parallel() = %d\n", omp_in_parallel());
            printf("Total threads executing: %d\n", total_threads);
        }

        printf("Hello from Thread ID: %d\n", id);
    }

    return 0;
}