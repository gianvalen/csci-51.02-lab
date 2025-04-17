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
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define DATA_KEY 1234
#define STATUS_KEY 5678
#define SEM_KEY 9999
#define SIZE_KEY 1357

// Union for initializing the semaphore's value
union semun {
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

// Function for locking the semaphore
// sem_num = 0 (first semaphore in the set)
// sem_op = -1 (which decrements)
// sem_flg = 0 (which means no special flags are set)
void semaphore_lock(int semid) {
    struct sembuf op = {0, -1, 0};
    semop(semid, &op, 1);
}

// Function for unlocking the semaphore
// sem_num = 0 (first semaphore in the set)
// sem_op = 1 (which increments)
// sem_flg = 0 (which means no special flags are set)
void semaphore_unlock(int semid) {
    struct sembuf op = {0, 1, 0};
    semop(semid, &op, 1);
}

int main(int argc, char* argv[]) {
    // Check for correct command-line usage
    if (argc != 3) {
        fprintf(stderr, "Incorrect usage\n");
        return 1;
    }

    // Get filename and shared memory size from arguments
    const char* filename = argv[1];
    int shm_size = atoi(argv[2]);

    // Create a semaphore
    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        return 1;
    }

    // Initialize the semaphore to 1 (available)
    union semun arg;
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg); // In the semaphore set with this "semid", "SET" the "VAL"ue of semaphore index "0" to "arg" (which is 1)

    // Create shared memory segments
    int data_shmid = shmget(DATA_KEY, shm_size, IPC_CREAT | 0666);       // For data buffer
    int status_shmid = shmget(STATUS_KEY, 2, IPC_CREAT | 0666);          // For status flag
    int size_shmid = shmget(SIZE_KEY, sizeof(int), IPC_CREAT | 0666);    // For byte count

    // Check if shared memory creation was successful
    if (data_shmid < 0 || status_shmid < 0 || size_shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach pointers to shared memory segments
    char* data = (char*)shmat(data_shmid, NULL, 0);     // Pointer to data buffer
    char* status = (char*)shmat(status_shmid, NULL, 0); // Pointer to status flag
    int* size = (int*)shmat(size_shmid, NULL, 0);       // Pointer to byte count

    // Open input file in binary read mode
    // r = read; b = binary
    FILE* file = fopen(filename, "rb");

    // Initialize status flag to empty
    status[0] = '\0';

    // Start producer loop
    while (1) {
        sleep(1);
        semaphore_lock(semid);  // Lock semaphore before accessing shared memory

        // \0 = no data
        // R = data has been read by consumer
        // W = data has been written by producer
        // D = done; no more data to process

        // Proceed only if no data or data has been read by consumer
        if (status[0] == '\0' || status[0] == 'R') {
            int bytes_read = fread(data, 1, shm_size, file);  // Read from file
            printf("Producer: Read %d bytes\n", bytes_read);

            if (bytes_read > 0) {
                *size = bytes_read;  // Store number of bytes actually read

                // Pad remaining memory with 0 if partial block read
                if (bytes_read < shm_size) {
                    memset(data + bytes_read, 0, shm_size - bytes_read); // Starting from address "data + bytes_read", set bytes to "0" "shm_size - bytes_read" times
                }

                status[0] = 'W';  // Set flag to 'W' to indicate data is ready
                printf("Producer: Data written, status set to 'W'\n");
            } else {
                status[0] = 'D';  // Set flag to 'D' to indicate Done
                printf("Producer: Done writing\n");
                semaphore_unlock(semid);
                break;  // Exit loop
            }
        }

        semaphore_unlock(semid);  // Release semaphore
    }

    // Detach shared memory and close file
    shmdt(data);
    shmdt(status);
    shmdt(size);
    fclose(file);

    printf("Producer done.\n");
    return 0;
}
