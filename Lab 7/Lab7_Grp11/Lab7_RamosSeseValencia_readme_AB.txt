# Lab 7: Concurrent Processes : POSIX Threads created by Jade Ramos, Rafael Sese, and Gian Valencia

## Description (Code A)
This program creates multiple threads to modify an array of integers by cubing even-indexed elements and negating odd-indexed elements. The code includes:
- A thread function that processes array elements based on their index
- Dynamic memory allocation for the array and threads

## How to Run (Code A)
1. Compile the program using: 

gcc -o Lab7a -lpthread Lab7_RamosSeseValencia_codeA.c
gcc -o lab7b -lpthread Lab7_RamosSeseValencia_codeB.c -lm

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

gcc -o lab7b -lpthread Lab7_RamosSeseValencia_codeB.c -lm

2. Run the executable with the format ./Lab7b N X:

Ex:
./Lab7a 4 0.5

3. Expected output for example

