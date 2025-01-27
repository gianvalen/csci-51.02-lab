// Jade Connery B. Ramos ()
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
using namespace std;

int main() {
    int totalAgents;
    cin >> totalAgents;  // Read the number of agents

    for (int i = 1; i <= totalAgents; ++i) {
        int x, y; // x and y are the first two integers of lines following the first line
        string s; // s is the string that will come after the first two integers

        cin >> x >> y;  // Read the two integers

        getline(cin, s);  // Read the rest of the line (the string the agent says)

        cout << "Agent#" << i << " is at (" << x << ", " << y << ")\n";
        cout << "Says:" << s << "\n";  // Print the string
    }

    return 0;
}