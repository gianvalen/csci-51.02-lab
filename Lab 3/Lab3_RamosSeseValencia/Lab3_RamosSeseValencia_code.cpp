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

// Define the IntNode struct which represents a single node in the stack
struct IntNode {
    int number; // Stores the integer value
    IntNode* next; // Pointer to the next node

    // Constructor to initialize a node with using an integer n
    IntNode(int n) {
        number = n;
        next = nullptr;
    }
};

// Define the IntStack struct using the concept of linked lists
struct IntStack {
    IntNode* top; // Pointer to the top node of the stack

    // Constructor to initialize an empty stack
    IntStack() {
        top = nullptr;
    }

    // push(n) - to add a new integer n to the top of the stack
    void push(int n) {
        IntNode* newNode = new IntNode(n);
        newNode->next = top; // Connect the new node to the current top node of the stack
        top = newNode;
        cout << n << " was pushed onto the stack." << endl;
    }

    // pop() - to remove and return the integer from the top of the stack
    void pop() {
        if (top == nullptr) { // Check if stack is empty
            cout << "Stack is empty. Cannot pop." << endl;
        }

        IntNode* temp = top; // Pointer to the node being removed
        int poppedNumber = temp->number;
        top = top->next;

        cout << poppedNumber << " popped from the stack." << endl;
        delete temp; // Free the memory to avoid memory leaks
    }

    // displayStack() to display the contents of the stack
    void displayStack() {
        IntNode* current = top;
        cout << "Stack contents from top to bottom: ";
        while (current != nullptr) {
            cout << current->number << " ";
            current = current->next; // The next node is now the "current"
        }
        cout << endl;
    }

    // Destructor to clean up
    ~IntStack() {
        while (top != nullptr) {
            IntNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main(void) {
    IntStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.displayStack();

    stack.pop();
    stack.pop();

    stack.displayStack();

    return 0;
}