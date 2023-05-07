void decode_huff(node * root, string s) {
    node *temp = new node;
    temp = root;
    int len = s.length();
    int i =0;
    while(i<=len){
        if(temp->left== NULL && temp->right ==NULL){
            cout<<temp->data;
            temp = root;
        }
        if(s[i]=='1'){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
        i++;
    }
}
