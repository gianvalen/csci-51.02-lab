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
using namespace std;

int multiply(int x, int factor) {
    // Take the smaller number as factor for less iterations in CASE 3
    if (x < factor) {
        swap(x, factor);
    }
    // CASE 1: Factor is 0
    if (factor == 0) {
        return 0;
    }
    // Store sign and work with absolute value
    bool isNegative = (factor < 0);
    factor = abs(factor);

    // CASE 2: Factor is a sum of powers of 2
    int result = 0, shift = 0;
    int tempFactor = factor;

    while (tempFactor > 0) {
        if (tempFactor & 1) { // If current bit is set
            result += (x << shift);
        }
        shift++;
        tempFactor >>= 1; // Move to the next bit
    }

    // Restore sign if needed
    if (isNegative) {  
        return -result;  
    } else {  
        return result;  
    }
}

int main() {
    int x, factor;
    
    cout << "Enter a number: ";
    cin >> x;
    cout << "Enter a factor: ";
    cin >> factor;

    int result = multiply(x, factor);
    cout << "Result: " << result << endl;

    return 0;
}
