#include <iostream>
#include <unistd.h>  // For execv()
#include <cstdlib>   // For exit()

using namespace std;

int main(int argc, char* argv[]) {
    // Define the new program to execute (e.g., gedit or ls)
    char* args[] = { (char*)"/usr/bin/gedit", (char*)NULL };

    cout << "Before execv() is called..." << endl;

    // Attempt to replace the current process with gedit
    if (execv(args[0], args) == -1) {
        // If execv fails, print an error message
        perror("execv failed");  // Prints system error message
        cout << "Error. Booooo!" << endl;
    }

    // This line will only be printed if execv() fails
    cout << "Will this line still be printed?" << endl;

    return 0;
}
