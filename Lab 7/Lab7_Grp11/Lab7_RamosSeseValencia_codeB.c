// Jade Connery B. Ramos (225198)
// Rafael Angelo A. Sese (225807)
// Gian Carlo D. Valencia (226584)
// 3 BS CS
// CSCI 51.02-F

// I hereby attest to the truth of the following facts:

// I have not discussed the C++ code in my program with anyone
// other than my instructor or the teaching assistants assigned to this course.
// I have not used C++ code obtained from another student, or
// any other unauthorized source, whether modified or unmodified.
// If any C++ code or documentation used in my program was
// obtained from another source, it has been clearly noted with citations in the
// comments of my program.

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
void* sin_taylor(void *arg) {
    ThreadArg *thread_arg = (ThreadArg*)arg;
    int thread_id = thread_arg->thread_id;
    int N = thread_arg->N;

    // Set every term's initial sum to 0. This will be modified later on once computation is complete
    long double term_sum = 0.0;
    int n = thread_id;

    while (1) {
        // Tracker
        printf("Thread %d: Computing term for n=%d with N=%d\n", thread_id, n, N);
        sleep(1);

        // Compute for term n
        int exp = 2 * n + 1;
        long double numerator = powl(x, exp);       // x^(2n+1)
        long double denominator = tgammal(exp + 1); // (2n+1)!
        long double term = numerator / denominator;

        // If computed term is "insignificant enough", end while loop
        if ((term < 0 ? -term : term) < 1e-16) {
            break;
        }

        // Even terms are positive, Odd terms are negative
        if (n % 2 == 0) {
            term_sum += term;
        } else {
            term_sum -= term;
        }

        // Move to the thread's next term to compute.
        // For example, if the are 4 threads, thread 0 will compute for n = 0, 4, 8, 12...
        n += N;
    }

    // Store term_sum in the sum array
    sum[thread_id] = term_sum;

    printf("Thread %d: Finished calculating terms, partial sum = %.15Lf\n", thread_id, term_sum);
    free(arg);

    return NULL;
}

int main(int argc, char *argv[]) {

    // Make sure to parse input arguments
    int N = atoi(argv[1]); // Number of threads
    x = strtold(argv[2], NULL); // Argument X for the sin function

    // Array to store sums
    sum = malloc(sizeof(long double) * N);

    // Array to store thread IDs (needed to pass index to each thread)
    pthread_t *threads = malloc(sizeof(pthread_t) * N);

    // Create threads
    for (int i = 0; i < N; i++) {
        ThreadArg *arg = malloc(sizeof(ThreadArg));

        // Assign values to struct's members
        arg->thread_id = i;
        arg->N = N;

        pthread_create(&threads[i], NULL, sin_taylor, arg);
    }

    // Wait for all threads to finish
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Sum the results from all threads to get the final value of sin(x)
    long double final_sum = 0.0;
    for (int i = 0; i < N; i++) {
        final_sum += sum[i];
    }

    // Compare with the built-in sinl(x) function
    printf("\nComparisons\n");
    printf("Calculated sin(x) = %.15Lf\n", final_sum);
    printf("Built-in sinl(x) = %.15Lf\n", sinl(x));

    // Clean up
    free(threads);
    free(sum);

    return 0;
}