#include <stdio.h>
#include <omp.h>

// Define a global nested lock instance [00:01:10]
omp_nest_lock_t my_nest_lock; 

void test_function(int step) {
    // OMP SET NEST LOCK: Safely acquires lock or increments nesting count [00:01:43]
    omp_set_nest_lock(&my_nest_lock); 
    
    int id = omp_get_thread_num();
    printf("Thread %d acquired lock - Step %d\n", id, step);

    // Demonstration of recursive acquisition (nested capability)
    if (step < 2) {
        test_function(step + 1); 
    }

    // OMP UNSET NEST LOCK: Decrements lock nesting or releases it completely [00:01:48]
    omp_unset_nest_lock(&my_nest_lock); 
}

int main() {
    // OMP INIT NEST LOCK: Initializes the lock object before usage [00:01:53]
    omp_init_nest_lock(&my_nest_lock);

    #pragma omp parallel num_threads(3)
    {
        // Threads compete to safely call the nested function
        test_function(1);
    }

    // Always destroy locks when finished to free system resources
    omp_destroy_nest_lock(&my_nest_lock);
    return 0;
}