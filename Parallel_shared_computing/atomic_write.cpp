#include <stdio.h>
#include <omp.h>

int main() {
    int array[5] = {10, 10, 10, 10, 10};
    int total_sum = 0;

    #pragma omp parallel for
    for(int i = 0; i < 5; i++) {
        // Safely add and write to the total_sum
        #pragma omp atomic write
        total_sum = total_sum + array[i]; 
    }

    // Output will consistently be 50
    printf("Total Sum: %d\n", total_sum);
    return 0;
}