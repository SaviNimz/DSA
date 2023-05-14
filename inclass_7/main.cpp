#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};


void traverseInOrder(struct node *root) {
  if (root == NULL)
      return;

    /* first recur on left child */
  traverseInOrder(root->left);

    /* then print the data of node */
  cout << root-> key << " ";

    /* now recur on right child */
  traverseInOrder(root->right);

}

// this is a helper function for insert node function
// this will create a new node on the heap memory
node* getNode(int data){
    node* new_node = new node(); // this will create a new node in the heap memory
    new_node -> key = data; // this will assign the value passed as the parameter to the node pointed by new_node pointer

    new_node -> left = NULL; // we need to set the left and right values node which is pointed by the new_node pointer to NULL
    new_node -> right = NULL;

    return new_node; // finally we return the pointer to the new node we created
}

// Insert a node
struct node *insertNode(struct node *node, int data) {

  if(node == NULL){
    // here we are creating a new node
    node = getNode(data);
    return node;
  }
  else if (node -> key > data){
    node -> left = insertNode(node -> left , data);
  }
  else{
    node -> right = insertNode(node -> right , data);
  }

  return node;

}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    // deleting a node has three cases
    if (!root) return root;

    if (key < root->key) root->left= deleteNode (root->left, key);

    else if (key>root->key) root->right= deleteNode (root->right, key);

    else{
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        node* temp= root->right;
        while (temp->left) temp=temp->left;
        root->key=temp->key;
        root->right=deleteNode(root->right,root->key);
        }
    return root;

}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  traverseInOrder(root);
}
