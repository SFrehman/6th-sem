#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    // Declared outside the parallel region -> Candidates for Shared
    int total_limit = 10;
    int shared_accumulator = 0;

    omp_set_num_threads(3);

    std::cout << "--- Starting OpenMP Scoping Demo ---\n\n";

    // Best Practice: default(none) forces us to explicitly state what 'total_limit' 
    // and 'shared_accumulator' are. Loop variables ('i') are automatically private.
    #pragma omp parallel default(none) shared(total_limit, shared_accumulator)
    {
        // 1. Private variable by declaration:
        // Because 'thread_local_val' is declared INSIDE the parallel region,
        // every thread gets its own isolated instance automatically. [00:01:08, 00:02:46]
        int thread_local_val = omp_get_thread_num() * 10;

        // 2. Accessing the shared variable safely
        // 'total_limit' can be safely read by all threads simultaneously [00:01:45].
        if (thread_local_val > total_limit) {
            
            // 3. Modifying a Shared Variable:
            // Since 'shared_accumulator' is shared, modifying it without protection 
            // creates a race condition. We use a critical section here to ensure safety.
            #pragma omp critical
            {
                shared_accumulator += thread_local_val;
            }
        }

        // Implicit loop counter rule demo:
        // Even though 'i' isn't explicitly scoped, loop indices inside parallel loops are private.
        #pragma omp for
        for (int i = 0; i < 3; ++i) {
            // 'i' is unique to each thread to ensure correct iteration distribution [00:00:58]
            std::cout << "Thread " << omp_get_thread_num() 
                      << " processing loop iteration i = " << i 
                      << " (Local local_val = " << thread_local_val << ")\n";
        }
    } // Join point [00:02:52]

    std::cout << "\n--- Parallel region ended ---\n";
    std::cout << "Final Shared Accumulator Value: " << shared_accumulator << "\n";

    return 0;
}