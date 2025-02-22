#include <iostream>
using namespace std;

int multiply(int x, int factor) {
    // CASE 1: Factor is 0
    if (factor == 0) {
        cout << "CASE 1" << endl; 
        return 0;
    }
    // Store sign and work with absolute value
    bool isNegative = (factor < 0);
    factor = abs(factor);

    // CASE 2: Factor is a power of 2
    if ((factor & (factor - 1)) == 0) { // & = bitwise AND
        cout << "CASE 2" << endl;
        int shift = 0;
        // Find the smallest power of 2 that is greater than or equal to the factor
        while ((1 << shift) < factor) { 
            shift++;  
        }
        // Perform the shift operation and adjust for negativity if needed
        if (isNegative) {  
            return -(x << shift);  
        } else {  
            return (x << shift);  
        }
    }
    // CASE 3: Factor is a sum of powers of 2
    // Try to express factor as a sum of powers of 2
    int result = 0, shift = 0;
    int tempFactor = factor;

    cout << "CASE 3" << endl;
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
