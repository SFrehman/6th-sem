#include <iostream>
#include <vector>
#include <omp.h> // Include OpenMP library [00:02:43]

int main() {
    const int NUM_THREADS = 4;
    const int N = 100;
    
    // An array to store the intermediate sum of each thread [00:02:52]
    // WARNING: This layout causes False Sharing!
    int thread_sum[NUM_THREADS] = {0}; 

    omp_set_num_threads(NUM_THREADS); // Set compiler to use 4 threads [00:03:08]

    #pragma omp parallel // Start parallel region [00:03:17]
    {
        int id = omp_get_thread_num(); // Get thread ID (0, 1, 2, or 3) [00:03:42]
        thread_sum[id] = 0;           // Initialize thread-specific position [00:03:50]

        // Manually chunking the loop: 100 iterations / 4 threads = 25 iterations per thread
        int chunk_size = N / NUM_THREADS;
        int start_idx = (id * chunk_size) + 1; // Thread 0 starts at 1, Thread 1 at 26...
        int end_idx = start_idx + chunk_size - 1;

        // Each thread calculates its assigned slice [00:04:05]
        for (int i = start_idx; i <= end_idx; ++i) {
            thread_sum[id] += i; // Storing intermediate values triggers False Sharing [00:04:14]
        }
    } // End of parallel region - implicit join [00:04:22]

    // Back to serial execution on master thread [00:04:22]
    int total_sum = 0;
    for (int i = 0; i < NUM_THREADS; ++i) {
        total_sum += thread_sum[i]; // Combine the results of all 4 blocks [00:04:30]
    }

    std::cout << "The total sum of 1 to 100 is: " << total_sum << "\n"; // Outputs 5050 [00:01:54]
    return 0;
}