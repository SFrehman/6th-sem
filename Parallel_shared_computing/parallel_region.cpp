#include <iostream>
#include <omp.h> // Essential OpenMP header file [00:01:06]

int main() {
    // 1. Serial execution before the parallel region (Runs only once) [00:02:30]
    std::cout << "--- Starting program in the serial region ---\n\n";

    // 2. Explicitly setting the team size to 4 threads [00:03:24]
    int requested_threads = 4;
    omp_set_num_threads(requested_threads);

    // 3. The Parallel Region Construct [00:01:14]
    // The master thread forks into a team of threads at the opening bracket '{'
    #pragma omp parallel 
    {
        // Code inside these brackets is executed by EVERY thread simultaneously [00:02:05]
        
        // Retrieve the unique ID of the executing thread [00:04:27]
        int thread_id = omp_get_thread_num();
        
        // Note: Standard std::cout is shared. Interleaving text might happen 
        // because threads write to the console simultaneously [00:04:44].
        std::cout << "Hello World from Thread ID: " << thread_id << "\n";
    } 
    // Implicit Join: All threads terminate here except the Master Thread [00:02:52]

    // 4. Back to Serial Execution (Runs only on the Master Thread) [00:02:52]
    std::cout << "\n--- Parallel region ended. Back to the serial region ---\n";
    
    return 0;
}