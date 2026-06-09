#include <stdio.h>
#include <omp.h>

#define MAX 100

int main() {
    int count = 0;
    int captured_val;

    #pragma omp parallel num_threads(MAX)
    {
        // Atomically increments count and captures the result into captured_val
        #pragma omp atomic capture
        {
            count++;
            captured_val = count;
        }
    }

    printf("Final Captured Value: %d\n", captured_val);
    return 0;
}