#include <iostream>
#include <string>
using namespace std;

//create a node class for representing a node in linked list

class Node{
public:
    int data;
    Node* Next;

    Node(int value){
        data = value;
        Next = nullptr;
    }
};
// Stack class for implementing a stack using a linked list
class Stack {
    //stack required only one pointer which is the pointer to the top
private:
    Node* top;

public:
    Stack(){
        top = nullptr;
    }

    //create a function to push an element to the linked list
    void push(int value){
        //prepare a new node
        Node* new_node = new Node(value);
        //assign the value as the head of the linked list
        new_node -> Next = top;
        top = new_node;
        string val = to_string(value);
        cout << "pushed " << val <<" to the stack" <<endl;
    }
    //create a function to pop an element from the stack
    void pop(){
        //check if the stack is empty
        if (top == nullptr){
            cout << "Can not pop from an empty stack" << endl;
            return;
        }
        else{
            // store the top of the stack in a temporary variable
            Node* temp = top;
            int top_val = temp->data;
            //point top to it's next value (null)
            top = top -> Next;
            // delete the temporary variable that stored the top value
            delete temp;
            string val = to_string(top_val);
            cout << "popped "<< val << " from the stack" << endl;
        }
    }
};

// queue class for implementing a queue using a linked list
class Queue{
    // we need to maintain two pointers when creating a queue
private:
    Node* front; // Front of the queue
    Node* rear;// Rear of the queue
public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->Next = newNode;
        rear = newNode;
    }

    // Dequeue an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.";
            return;
        }
        Node* temp = front;
        front = front->Next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};


int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.push(6);
    stack.pop();
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
}
