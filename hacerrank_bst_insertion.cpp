
    Node * insert(Node * root, int data) {
        if(root==NULL) {
            Node* temp= new Node(data);
            return temp;
        }

        if(data <= root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);

        return root;
    }
