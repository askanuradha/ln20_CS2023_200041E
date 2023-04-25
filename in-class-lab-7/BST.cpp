#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Function to create a new node
node* createNode(int key) {
  node* newNode = new node;
  newNode->key = key;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == nullptr) {
      return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // If the tree is empty, create a new node and set it as the root
  if (node == nullptr) {
    node = createNode(key);
    return node;
  }
  // Otherwise, traverse the tree to find the correct position to insert the new node
  else {
    // If the data is less than the root node, insert it into the left subtree
    if (key < node->key) {
      node->left = insertNode(node->left, key);
    }
    // If the data is greater than the root node, insert it into the right subtree
    else {
      node->right = insertNode(node->right, key);
    }
    return node;
  }
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // If the tree is empty, return nullptr
  if (root == nullptr) {
    return root;
  }
  // Otherwise, traverse the tree to find the node to delete
  else if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }
  else {
    // If the node to delete has only one child or no children, simply remove it
    if (root->left == nullptr) {
      node* temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == nullptr) {
      node* temp = root->left;
      delete root;
      return temp;
    }
    // If the node to delete has two children, find the smallest node in the right subtree and replace the node to delete with it
    node* temp = root->right;
    while (temp->left != nullptr) {
      temp = temp->left;
    }
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