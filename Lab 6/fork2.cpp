#include <iostream>
#include <unistd.h> // for fork()
using namespace std;

int main() {
    if (fork() == 0) { 
        // First child
        cout << "Child 1: PID = " << getpid() << ", Parent PID = " << getppid() << endl;

        if (fork() == 0) { 
            // Second child (inside first child)
            cout << "Child 2: PID = " << getpid() << ", Parent PID = " << getppid() << endl;

            if (fork() == 0) { 
                // Third child (inside second child)
                cout << "Child 3: PID = " << getpid() << ", Parent PID = " << getppid() << endl;
            }
        }
    }
    else {
        // Parent process
        cout << "Parent: PID = " << getpid() << endl;
    }

    return 0;
}
