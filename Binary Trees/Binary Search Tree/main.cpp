#include <iostream>

using namespace std;

// There are two methods to implement a Node

// Method 1 (Using Structures)

struct node{
    int data; // this will store the data
    node* left; // left pointer to the next node
    node* right; // right pointer to the next node
};

// Method 2 (Using classes) || AND I WILL BE USING THIS METHOD HERE

class Node{
public:
    int data;
    Node* left;
    Node* right;
    // this class also has the same attributes as the above mentioned Structure

    //Lets create the constructor
    Node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// binary search trees have the same structure as binary trees ( It is also and recursive data structure)
// Left subtree only contains values less than ts root
// right sub tree only contains values greater than its root

//The above properties of the Binary Search Tree provide an ordering among keys so that the operations like search, minimum and maximum can be done fast

// Here I will use the structure to create my binary search tree ( You can also make a binary search tree class and implement methods as class methods)
// But I will just manually create a binary search tree here


// this function will return the pointer to the new node that we create
node* getNode(int data){
    node* new_node = new node(); // this will create a new node in the heap memory
    new_node -> data = data; // this will assign the value passed as the parameter to the node pointed by new_node pointer

    new_node -> left = NULL; // we need to set the left and right values node which is pointed by the new_node pointer to NULL
    new_node -> right = NULL;

    return new_node; // finally we return the pointer to the new node we created
}

// for insert a new node to a BST we need need implement a function which does the insertion n the specific way which binary search tree is defined

// here I will implement a function which inserts the given value to the BST and returns the pointer to the root node
// But we can also make a void function which modifies the original tree But it requires pointer to a pointer as a function parameter and  we have to pass the argument by reference

node* Insert(node* root,int data){
    //if the BST is empty insert the new node as head
    if (root == NULL){
        root = getNode(data); // by getNode function we are returning the pointer to the newly created node
        return root;
    }
    // if the value we try to insert is less than the root value we need to recursively insert the new node to the left sub tree
    else if (root -> data > data){
        root -> left = Insert(root -> left, data);
    }
    // if not ewe have to do the same thing for the right sub tree
    else{
        root -> right = Insert(root -> right , data);
    }

    return root;
}

// We can also find the minimum value and maximum value of the BST pretty easily
// because minimum value is always located in the left bottom corner and maximum is right bottom conor of the BST
int minimum_BST(node* root){
    //this function will return the minimum value of the BST

    node* temp = root;
    while (temp -> left != NULL){
        temp = temp -> left;
    }
    return temp-> data;
}
int maximum_BST(node* root){
    // this function will return the maximum value of the BST
    node*temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp -> data;
}


// Then lets look at the deletion operation is BST
// This is a bit trickier because even after the deletion we need to maintain the BST properties of the tree
// there are three cases which happen when deleting a node from a binary search tree



node* DeleteNode(node* root , int data){

    if (root == NULL){
        return root; // this is the base case
    }
    else if (root -> data > data){
        // recursively check in the right sub tree because it contains lesser values than the root
        DeleteNode(root -> right , data);
    }
    else if(root -> data < data){
        // recursively check in the left sub tree because it contains greater values than the root
        DeleteNode(root -> right , data);
    }
    else{
        //There are three cases that can happen when deleting a node
        //Case 1 : - No child
        if (root -> left == NULL && root -> right == NULL){
            delete root; // this delete will deallocate the memory
            root = NULL;
        }
        // case 2 :- Only one child
        else if(root -> left == NULL){
            // here only the left child is NULL
            node* temp = root; // store the current root in a temporary variable
            root = root -> right; // assgin the current root to its right child
            delete temp; // deallocate the memory used for temp
        }
        else if(root -> right == NULL){
            // here only right child is NULL
            node* temp = root;
            root = root -> left;
            delete temp;
        }
        else{
            node* temp = minimum_BST(root -> right);
            root -> data = temp -> data;
            root - > right = delete(root -> right , temp -> data);
        }
    }
    return root;

}


int main()
{
    // by the following way we can create our binary search tree
    node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);

}
