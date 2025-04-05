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

int *arr; // array for integers

// Define run function
void* run(void *arg) {
    int index = *(int*)arg;
    int old_val = arr[index];

    // If index is even, cube. Otherwise, negate.
    if (index % 2 == 0) {
        arr[index] = arr[index] * arr[index] * arr[index];
    } else {
        arr[index] = -arr[index];
    }

    // Print according to specification
    printf("arr[%d](%d) has been replaced with arr[%d](%d)\n", index, old_val, index, arr[index]);
    free(arg);
    return NULL;
}

int main(int argc, char *argv[]) {

    // Abort and print error if argc == 1
    if (argc == 1) {
        printf("Error.\n");
        return 1;
    }

    int count = argc - 1;

    // Fill the array
    arr = malloc(sizeof(int) * count);

    // Convert from string to int
    for (int i = 0; i < count; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    // Allocate pthread_t array
    pthread_t* threads = malloc(sizeof(pthread_t) * count);
    
    // Create threads
    for (int i = 0; i < count; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;

        pthread_create(&threads[i], NULL, run, arg);  
    }

    // Wait for threads to finish
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    free(arr);

    return 0;
}