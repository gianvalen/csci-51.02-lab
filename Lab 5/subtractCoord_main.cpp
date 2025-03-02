#include <iostream>
#include "getCoord_extern.cpp"
using namespace std;

int subtractCoord(Point3D p, Point3D q) {
    return p.x - q.x;
}

int main(void){
    Point3D p1 = {6, 2, 8};
    Point3D p2 = {3, 6, 9};

    cout << subtractCoord(p1, p2) << endl;
    return 0;
}
