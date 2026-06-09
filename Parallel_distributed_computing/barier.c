#include <stdio.h>
#include <omp.h>

int main() {
    int thread_id;
    int num_threads;

    // Launch parallel execution block; thread_id must be private to each thread
    #pragma omp parallel private(thread_id)
    {
        // Get the specific ID assigned to the current thread
        thread_id = omp_get_thread_num();
        
        // Every thread prints its greeting first
        printf("Hello World from thread %d\n", thread_id);

        // Explicit Barrier Synchronization Point
        // No thread crosses this point until all threads have completed their printf above
        #pragma omp barrier

        // Only thread 0 executes this section, guaranteed to run after all greetings
        if (thread_id == 0) {
            num_threads = omp_get_num_threads();
            printf("There are %d threads\n", num_threads);
        }
    }

    return 0;
}