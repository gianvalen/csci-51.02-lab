# Lab 6: Concurrent Processes created by Jade Ramos, Rafael Sese, and Gian Valencia

## Description
This program creates a parent and child process using fork(). The parent process continuously prints the current date and time every 10 seconds, while the child process launches the xclock program using execvp(). The code includes:
- A function for displaying time
- A child process that replaces itself with xclock
- A parent process that prints a message every third iteration

## How to Run
1. Compile the program using: 

g++ -o Lab6 Lab6_RamosSeseValencia_code.cpp

2. Run the executable:

./Lab6

3. Perform ctrl + C to terminate.