#include <stdio.h>
#include <omp.h>

void test(int val) {
    // The 'if' clause evaluates 'val'. If non-zero, it runs in parallel.
    #pragma omp parallel if(val)
    {
        // omp_in_parallel() returns 1 if running in a parallel region, 0 otherwise
        if (omp_in_parallel()) {
            // This executes if the OpenMP 'if' clause evaluated to true
            #pragma omp single
            {
                printf("Executed in PARALLEL with %d threads.\n", omp_get_num_threads());
            }
        } else {
            // This executes if the OpenMP 'if' clause evaluated to false
            printf("Executed in SERIAL mode by a single thread.\n");
        }
    }
}

int main() {
    // Set the target number of threads to 5
    omp_set_num_threads(5);

    printf("--- Calling test(0) ---\n");
    test(0); // Should execute in serial mode

    printf("\n--- Calling test(4) ---\n");
    test(4); // Should execute in parallel mode

    return 0;
}