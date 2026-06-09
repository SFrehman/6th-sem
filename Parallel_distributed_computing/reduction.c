#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    // Use 4 threads to divide the workload (25 iterations per thread)
    omp_set_num_threads(4);

    // 'reduction(+:sum)' tells OpenMP to give each thread a private copy of 'sum'
    // initialized to 0 (the identity value for addition)
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 100; i++) {
        // Each thread safely increments its own local private copy of 'sum'
        sum += i; 
    }
    // At the end of the loop, OpenMP automatically aggregates all 
    // private thread sums into the global 'sum' variable.

    // Expected mathematical result: (100 * 101) / 2 = 5050
    printf("The sum of the first 100 natural numbers is: %d\n", sum);

    return 0;
}