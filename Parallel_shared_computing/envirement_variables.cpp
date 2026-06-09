#include <iostream>
#include <omp.h>

int main() {
    // Querying configuration values set by environment variables
    std::cout << "=========================================\n";
    std::cout << "    OpenMP Initial Environment Status    \n";
    std::cout << "=========================================\n";
    std::cout << "Available Processors (Cores): " << omp_get_num_procs() << "\n";
    std::cout << "Max Allowed Threads (OMP_NUM_THREADS): " << omp_get_max_threads() << "\n";
    std::cout << "Dynamic Adjustment Enabled (OMP_DYNAMIC): " << (omp_get_dynamic() ? "True" : "False") << "\n";
    std::cout << "Nested Parallelism Enabled (OMP_NESTED): " << (omp_get_nested() ? "True" : "False") << "\n";
    std::cout << "=========================================\n\n";

    std::cout << "--- Starting Parallel Region ---\n";

    // A parallel region without an explicit 'num_threads' clause.
    // This forces OpenMP to rely entirely on the OMP_NUM_THREADS environment variable.
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        // Print from each active thread
        // Using explicit formatting blocks to prevent output stream interlacing (scrambling)
        #pragma omp critical
        {
            std::cout << "Hello World from Thread ID: " << thread_id 
                      << " (out of " << total_threads << " active threads)\n";
        }
    }

    std::cout << "--- Parallel Region Ended ---\n";
    return 0;
}