#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
// New Node
struct node* newNode(int item)
{
    struct node* temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
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
struct node *insertNode(struct node *node, int key) {
  if(node == nullptr){
        return newNode(key);
    }

    if(key<node->key){
        node->left= insertNode(node->left, key);
    }
    else{
        node->right = insertNode(node->right, key);
    }
    return node;
}
void searchKey(node* &curr, int key, node* &parent){
    while(curr != nullptr && curr->key != key){
        parent = curr;
        if(key<curr->key){
            curr= curr->left;
        }
        else{
            curr = curr->left;
        }

    }
}
node* getMinimum(node* curr){
    while (curr->left !=nullptr){
        curr = curr->left;
    }
    return curr;
}
// Deleting a node
struct node *deleteNode(struct node* &root, int key) {
    if(root == NULL){
        return root;
    }
    if(root->key>key){
        root->left = deleteNode(root->left,key);
    }
    else if(root->key<key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL & root-> right == NULL){
            return NULL;
        }
        else if(root->left ==NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            node *min = getMinimum(root);
            root->key = min->key;
            root->right = deleteNode(root->right,min->key);
        }
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