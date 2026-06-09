#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int maximum = 0;
    int array[5] = {12, 45, 78, 23, 56};
    int safe_max;

    #pragma omp parallel for
    for(int i = 0; i < 5; i++) {
        if(array[i] > maximum) {
            maximum = array[i];
        }
    }

    // Safely read the value of maximum into another variable
    #pragma omp atomic read
    safe_max = maximum;

    printf("Safe Maximum Element: %d\n", safe_max);
    return 0;
}