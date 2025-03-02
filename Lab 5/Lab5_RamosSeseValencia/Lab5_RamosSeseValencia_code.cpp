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

struct Point3D {
    int x, y, z;
};

// Function to compute Manhattan distance without cmath
int manhattanDistance(const Point3D& p1, const Point3D& p2) {
    int diffx = p1.x - p2.x;
    int diffy = p1.y - p2.y;
    int diffz = p1.z - p2.z;
    return abs(diffx) + abs(diffy) + abs(diffz);
}

int main() {
    int test_cases;
    cin >> test_cases; // Get the number of test cases

    for (int i = 0; i < test_cases; i++) { // Run exactly "test_cases" times
        int num_of_points;
        cin >> num_of_points;

        Point3D points[num_of_points]; // Use an array to store the points

        for (int i = 0; i < num_of_points; i++) { // Store the x y z values for each point
            cin >> points[i].x >> points[i].y >> points[i].z;
        }

        for (int i = 0; i < num_of_points - 1; i++) { // Get the Manhattan distance for adjacent points
            cout << manhattanDistance(points[i], points[i + 1]) << endl;
        }

        if (test_cases > 0) { // Blank line between each test case, for clear separation
            cout << endl;
        }
    }

    return 0;
}