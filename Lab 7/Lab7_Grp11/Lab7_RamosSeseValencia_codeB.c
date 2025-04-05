#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

long double *sum; // global array to store partial sums from each thread
long double x;    // the value of x for sin(x)

// Struct to hold both thread ID and N
typedef struct {
    int thread_id;
    int N;
} ThreadArg;

// Thread function to compute the series terms
void* compute_terms(void *arg) {
    // Cast argument to access both thread_id and N
    ThreadArg *thread_arg = (ThreadArg*)arg;
    int thread_id = thread_arg->thread_id;
    int N = thread_arg->N;

    long double term_sum = 0.0;
    int n = thread_id;

    long double power_x = 1.0;    // x^(2n+1)
    long double factorial = 1.0;  // (2n+1)!

    // Compute terms for the thread's index
    while (1) {
        // Print which thread is working
        printf("Thread %d: Computing term for n=%d\n", thread_id, n);
        
        // Sleep for 1 second to simulate work and allow for parallel execution observation
        sleep(1);

        // Increment power of x (x^(2n+1)) and factorial (factorial of (2n+1))
        if (n > thread_id) {
            power_x *= x * x; // Update power_x to be x^(2n+1)
            factorial *= (2 * n) * (2 * n + 1); // Update factorial for (2n+1)!
        }

        // Calculate the current term using the running power_x and factorial
        long double term = power_x / factorial;
        
        // Check if the absolute value of the term is sufficiently small
        if (fabsl(term) < 1e-5) {
            break;
        }

        // If the term is even index, add it, otherwise subtract it
        if (n % 2 == 0) {
            term_sum += term;
        } else {
            term_sum -= term;
        }

        // Move to the next term (i.e., increment the thread's specific term index by N)
        n += N;
    }

    sum[thread_id] = term_sum; // Save the partial sum for this thread
    printf("Thread %d: Finished calculating terms, partial sum = %.15Lf\n", thread_id, term_sum);
    free(arg); // Free memory allocated for the thread argument
    return NULL;
}

int main(int argc, char *argv[]) {

    // Make sure to parse input arguments
    int N = atoi(argv[1]); // Number of threads
    x = strtold(argv[2], NULL); // Argument X for the sin function (long double)


    // Allocate memory for the sum array
    sum = malloc(sizeof(long double) * N);

    // Array to store thread IDs (needed to pass index to each thread)
    pthread_t *threads = malloc(sizeof(pthread_t) * N);

    // Create threads
    for (int i = 0; i < N; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;

        pthread_create(&threads[i], NULL, compute_terms, arg);
    }

    // Wait for all threads to complete
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Sum the results from all threads to get the final value of sin(x)
    long double final_sum = 0.0;
    for (int i = 0; i < N; i++) {
        final_sum += sum[i];
    }

    // Compare with the built-in sinl(x) function
    printf("Calculated sin(x) = %.15Lf\n", final_sum);
    printf("Built-in sinl(x) = %.15Lf\n", sinl(x));

    // Clean up
    free(threads);
    free(sum);

    return 0;
}
