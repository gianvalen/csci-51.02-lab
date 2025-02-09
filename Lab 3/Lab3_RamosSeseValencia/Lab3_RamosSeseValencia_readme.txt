# Lab 3: Stack Implementation Using Linked List created by Jade Ramos, Rafael Sese, and Gian Valencia

## Description
This program implements a stack of integers using linked lists instead of arrays. The code includes:
- IntNode struct to define a node.
- Linked list creation and traversal demonstration.
- IntStack struct with push, pop, and display functions.
- A main function to demonstrate the creation and traversal in the IntStack

## Functions
The stack has three functions: push, pop, and displayStack.

- push() requires an argument. This is the int that will be pushed onto the stack.
e.g 
stack.push(1)
stack.push(-100)
stack.push(69)

- pop() does not require an argument. This removes the topmost element on the stack.
e.g 
stack.pop()

- displayStack() does not require an argument. This displays the stack from top to bottom.
e.g 
stack.displayStack()
Output: 30 20 10

## How to Run
1. Compile the program using: 

g++ -o Lab3 Lab3_RamosSeseValencia_code.cpp

2. Run the executable:

./Lab3

3. (Optional) You may edit the main function to do more "functions" on the stack



