#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;
// create a class for the stack
// In this class stack will be implemented using an array

class Stack_using_array {
private:
    int top; // index of the top element in the stack
    int len; // maximum size of the stack
    int* stack; // pointer to the dynamically allocated array

public:
    // initialize the stack using the constructor
    Stack_using_array(int len) {
        this->len = len;
        stack = new int[len];
        top = -1; // stack is initially empty
    }

    // push an element onto the top of the stack
    void push(int val) {
        if (top >= len - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            cout << "pushed " << to_string(val) <<endl;
            stack[top] = val;
        }
    }

    // remove and return the top element from the stack
    void pop() {
        if (top <= -1) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "The popped element is " << stack[top] << endl;
            top--;
        }
    }

    // print all the elements in the stack
    void display() {
        if (top >= 0) {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    // check if the stack is empty
    bool isEmpty() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return true;
        } else {
            cout << "Stack is not empty" << endl;
            return false;
        }
    }

    // check if the stack is full
    bool isFull() {
        if (top == len - 1) {
            cout << "Stack is full" << endl;
            return true;
        } else {
            cout << "Stack is not full" << endl;
            return false;
        }
    }

    // get the value of the top element in the stack
    int stackTop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return stack[top];
        }
    }
};

// create a Node class and it's constructor for the linked list implementation

class Node {
public:
    int data;
    Node* Next;

    Node(int value) {
        data = value;
        Next = nullptr;
    }
};

// create a class for the Stack
//In this class stack will be implemented using a linked list

class Stack_using_linkedlist {
private:
    // we need to have a pointer to keep track of the head of the linked list
    // main reason for using a linked list to build a stack is we don't need to specify the size and we have the ability to insert
    Node* top;
public:
    Stack_using_linkedlist() {
        top = nullptr;
    }
    // now we just have to implement the above functionalities of the stack to this class
    // we will push and pop the values from the head of the linked list because it would be
    // efficent because it just takes O(1) time
    bool isEmpty() {
        return top == nullptr;
    }

    bool isFull() {
        Node* temp = new Node(0);
        if (temp == nullptr) {
            return true;
        }
        delete temp;
        return false;
    }
    // push a value to the stack
    void push(int value) {

        Node* new_node = new Node(value);
        new_node->Next = top;
        top = new_node;
        string val = to_string(value);
        cout << "pushed " << val << endl;
    }
    // pop a value from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Can not pop from an empty stack" << endl;
            return;
        }
        else {
            Node* temp = top;
            int top_val = temp->data;
            top = top->Next;
            delete temp;
            string val = to_string(top_val);
            cout << "popped " << val << " from the stack" << endl;
        }
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return -1;
        }
        else {
            return top->data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        else {
            cout << "The elements in the stack are: ";
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->Next;
            }
            cout << endl;
        }
    }
};


int main()
{
    // test for the array representation
    cout << "TESTING THE ARRAY REPRESENTATION OF THE STACK" <<endl;
    Stack_using_array test(100);
    auto startA= high_resolution_clock::now();

    for (int i=0; i<10; i++){
        int num =rand() % 100;
        test.push(num);
    }

    test.display();

    for (int i=0; i<5; i++){
        test.pop();
    }

    test.display();

    for (int i=0; i<4; i++){
        int num =rand() % 100;
        test.push(num);
    }
    test.display();

    auto stopA = high_resolution_clock::now();
    auto durationA = duration_cast <microseconds> (stopA-startA);

    cout << "Time duration for Array Representation is " << durationA.count()<< endl;
    cout << "-------------------------------------------------------------------------------------------------------------"<<endl;

    //Test for the Linked list representation

    cout << "TESTING THE LINKED LIST REPRESENTATION OF THE STACK" <<endl;
    Stack_using_linkedlist test_2;
    auto startL= high_resolution_clock::now();

    for (int i=0; i<10; i++){
        int num =rand() % 100;
        test_2.push(num);
    }

    test_2.display();

    for (int i=0; i<5; i++){
        test_2.pop();
    }

    test_2.display();

    for (int i=0; i<4; i++){
        int num =rand() % 100;
        test_2.push(num);
    }
    test_2.display();

    auto stopL = high_resolution_clock::now();
    auto durationL = duration_cast <microseconds> (stopL-startL);

    cout << "Time duration for Linked list Representation is " << durationL.count()<< endl;
    cout << "-------------------------------------------------------------------------------------------------------------"<<endl;
}




