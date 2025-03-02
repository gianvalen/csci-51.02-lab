#include <iostream>
using namespace std;

int ret(int* x){
    int i = 0;
    int ret = 0;
   
    while (*x > 0){
        ret += *x;
        x += 1;
        cout << x << endl;
    }
    return ret;
}

int main(void){
    int a[4];
    a[0] = 5;
    a[1] = 3;
    a[2] = 9;
    a[3] = 0;

    cout << ret(a) << endl;
    return 0;
}
