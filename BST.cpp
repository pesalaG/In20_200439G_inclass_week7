#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL)
  {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL) 
  {
    struct node *temp = new node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }
  //insert node to the left
  if (key < root->key){
    root->left = insertNode(root->left, key);     
  }
  //insert node to the right
  else if (key > root->key){
    root->right = insertNode(root->right, key);
  }
  return root;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{
  if (root == NULL)
    return root;

//continue to find the node with key value to delete
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

//when traversed to the the node to be deleted
  else {
    if (root->left == NULL and root->right == NULL)
            {return NULL;}
            
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    struct node *temp = root->right;
    while (temp->left != NULL)
      temp = temp->left;

    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
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