#include <iostream>
#include <queue>
using namespace std;

// here I will implement binary tree in c++ language

// building block of a binary tree is a Node object
// This object has a value and two pointers which are left and right pointers to is children nodes

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


// Traversing the tree

//(1) DFS : - we have three ways to travel dfs in binary trees

// pre order traversal
void preorder(Node* root){

    // define the base case
    if (root == NULL){
        return;
    }
    // root , left , right
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

// in order traversal
void inorder(Node* root){

    // define the base case
    if (root == NULL){
        return;
    }
    //left,root,right
    inorder(root->left);
    cout << root -> data << " ";
    inorder(root -> right);
}

//postorder traversal
void postorder(Node* root){

    //define the base case
    if (root == NULL){
        return;
    }
    //left,right,root
    postorder(root -> left);
    postorder(root -> right);
    cout << root-> data << " ";
}


// (2) BFS : - we use level order traversal for this and this uses a queue data structure

void levelOrder(Node* root){

    // define base case
    if (root == NULL){
        return;
    }
    // create an empty queue for level order traversal
    queue<Node*> temp;
    temp.push(root);

    while(temp.empty() == false){

        Node* curr = temp.front();
        cout << curr -> data << " ";
        temp.pop();
        if (curr -> left != NULL){
            temp.push(curr -> left);
        }
        if (curr -> right != NULL){
            temp.push(curr -> right);
        }
    }
}

// now  i will implement few other basic functions which can perform on the binary tree

int max_height(Node* root){
    // returns the maximum height of the binary tree
    if (root == NULL){
        // handling the base case
        return 0;
    }
    return max(max_height(root -> left),max_height(root -> right)) + 1;
}

int node_count(Node* root){
    // returns the total number of nodes in the tree
    if (root == NULL){
        // handling the base case which is the case with no node
        return 0;
    }
    int total = 1 + max_height(root -> left) + max_height(root -> right);
    return total;
}

int main()
{
    /*create root*/
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

//    preorder(root);
//    cout << endl;
//    levelOrder(root);
    int val = max_height(root);
    cout << val;
}


