# Lab 7: Concurrent Processes : POSIX Threads created by Jade Ramos, Rafael Sese, and Gian Valencia

## Description (Code A)
This program creates multiple threads to modify an array of integers by cubing even-indexed elements and negating odd-indexed elements. The code includes:
- A thread function that processes array elements based on their index
- Dynamic memory allocation for the array and threads

## How to Run (Code A)
1. Compile the program using: 

gcc -o Lab7a -lpthread Lab7_RamosSeseValencia_codeA.c

2. Run the executable followed by integers:

Ex:
./Lab7a 1 2 3

3. Expected output for example

arr[0](1) has been replaced with arr[0](1)
arr[1](2) has been replaced with arr[1](-2)
arr[2](3) has been replaced with arr[2](27)



## Description (Code B)
This program uses multiple threads to compute the sine of a given value using its Taylor series expansion. The code includes:
- A thread function that calculates terms of the series
- Dynamic memory allocation for the sum array and threads

## How to Run (Code B)
1. Compile the program using: 

gcc -o Lab7b -lpthread Lab7_RamosSeseValencia_codeB.c -lm

2. Run the executable with the format "./Lab7b N X":

Ex:
./Lab7b 4 1

3. Expected output for example

Thread 0: Computing term for n=0 with N=4
Thread 1: Computing term for n=1 with N=4
Thread 2: Computing term for n=2 with N=4
Thread 3: Computing term for n=3 with N=4
Thread 0: Computing term for n=4 with N=4
Thread 2: Computing term for n=6 with N=4
Thread 1: Computing term for n=5 with N=4
Thread 3: Computing term for n=7 with N=4
Thread 2: Computing term for n=10 with N=4
Thread 0: Computing term for n=8 with N=4
Thread 3: Computing term for n=11 with N=4
Thread 1: Computing term for n=9 with N=4
Thread 2: Finished calculating terms, partial sum = 0.008333333493924
Thread 0: Computing term for n=12 with N=4
Thread 1: Finished calculating terms, partial sum = -0.166666691718775
Thread 3: Finished calculating terms, partial sum = -0.000198412699177
Thread 0: Finished calculating terms, partial sum = 1.000002755731925

Comparisons
Calculated sin(x) = 0.841470984807897
Built-in sinl(x) = 0.841470984807897