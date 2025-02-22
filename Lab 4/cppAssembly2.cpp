//cppAssembly2.cpp
int dummy(int a, int b){
    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;
    return 0;
}

// still in cppAssembly2.cpp, after dummy( )
int main(void){
    int temp = dummy(19,3);
    int temp1 = dummy(10,20);
    int temp2 = dummy(30,40);
    int temp3 = dummy(50,60);
    return temp;
}   