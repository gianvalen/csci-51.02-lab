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

#include <iostream>
#include <unistd.h>
#include <ctime>      // For time functions
#include <sys/wait.h> // For wait()
using namespace std;

// Function to get the current date/time
void printTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // [yyyy-mm-dd] hh:mm:ss
    cout << "["
         << 1900 + ltm->tm_year << "-"  // Year
         << (ltm->tm_mon + 1) << "-"    // Month
         << ltm->tm_mday << "] "        // Day
         << ltm->tm_hour << ":"         // Hours
         << ltm->tm_min << ":"          // Minutes
         << ltm->tm_sec << endl;        // Seconds
}

int main() {
    int pid = fork(); // Create a child process

    // If fork() returns a negative value, the creation of a child process was unsuccessful
    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    }
    
    // child process
    if (pid == 0) {
        cout << "Child process started, launching xclock..." << endl;

        // First argument is the name of the program, second argument is NULL
        char *args[] = { (char*)"myXclock", (char*)NULL }; 
        
        // Replace the child process with xclock
        execvp("/usr/bin/xclock", args); 
        
        // If execvp() fails, print an error and exit
        perror("execvp failed"); 
        exit(1);
    } 

    // parent process
    else {
        cout << "Parent process started, printing time every 10 seconds..." << endl;

        int count = 0;

        while (true) {
            sleep(10); // Pause for 10 seconds
            printTime();
            count++;

            // Every third print out, print a warning message to the user
            if (count % 3 == 0) {
                cout << "\"This program has gone on for far too long. Type Ctrl+C to abort this timer application.\"" << endl;
            }
        }
    }

    return 0;
}
