bool bstUtil(Node* root, int min, int max){
    if(root==NULL) return 1;
    if(root->data>min && root->data<max){
        return bstUtil(root->left,min,root->data) && bstUtil(root->right,root->data,max);
    }
    else return 0;
}
bool isBST(Node* root) {
    // Your code here
    return bstUtil(root, INT_MIN, INT_MAX);
}
