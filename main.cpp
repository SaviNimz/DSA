#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* Next;
};
int get_size(Node** head){

    // initialize variables for length and head
    int len = 0;
    Node* temp = *head;
    // while we find the NULL pointer increment the temp variable
    while(temp != NULL){
        len ++;
        temp = temp -> Next;
    }
    return len;

}
void printlist(Node* n){

    while (n!=NULL){
        cout << n -> value << " ";
        n = n -> Next;
    }
}
void insert_head(Node** head , int value){

    // prepare a new Node
    Node* temp = new Node;
    temp -> value = value;
    // put the newly created node in front of the head
    temp -> Next = *head;
    // move the head of the list to point to the new node
    *head = temp;
}
void insert_tail(Node** head , int val){

    // prepare a new node
    Node * temp = new Node;
    temp -> value = val;
    temp -> Next = NULL;
    // if list is empty assign the new node as head node
    if (*head == NULL){
        *head = temp;
        return;
    }
    //if list is not empty fine the last element of the list
    Node* last = *head;
    while(last -> Next != NULL){
        last = last -> Next;
    }
    // insert the new node after the last node
    last -> Next = temp;
}
void insertPosition (int pos, int data, Node ** head)
{
//prepare the new node
  Node *new_node = new Node ();
  new_node->value = data;
  new_node->Next = NULL;
// If the given position is the head position insert at the head
  if (pos == 1)
    {
      new_node->Next = *head;
      *head = new_node;
    }
// travel through the linked list until we find the given position
  else
    {
      Node *temp = *head;
      while (--pos > 1)
	{
	  temp = temp->Next;
	}
      new_node->Next = temp->Next;
      temp->Next = new_node;
    }
}

void delete_at_start(Node** head){

    // check if head is Null
    if (*head == NULL){
        cout << "list is empty";
        return;
    }
    // assign the head to a temporary variable and assign the next value to the head to the value of the head
    // deallocate the memory saved for the temporary variable
    Node* temp = *head;
    *head = (*head)->Next;
    delete temp;
}

void delete_at_end(Node* head){
    if (head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }
    if (head->Next == NULL) { // If there is only one node in the list
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->Next->Next != NULL) { // Traverse to the second last node
        temp = temp->Next;
    }
    Node* last = temp->Next; // Save the last node in a temporary pointer
    temp->Next = NULL; // Update the next pointer of the second last node
    // Find the new last node and delete the old last node
    while (temp->Next != NULL) {
        temp = temp->Next;
    }
    temp->Next = last;
}

void deleteat_position(Node** headRef, int position) {
    if (*headRef == NULL)
        return;

    Node* temp = *headRef;

    if (position == 0) {
        *headRef = temp->Next;
        delete temp;
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->Next;

    if (temp == NULL || temp->Next == NULL)
        return;

    Node* Next = temp->Next->Next;

    delete temp->Next;
    temp->Next = Next;
}
}

bool search_list(Node** head , int val){
    Node* current = *head;

    while (current != NULL){
        if (current -> value == val){
            return true;
        }
        current = current -> Next;
    }
    return false;
}


