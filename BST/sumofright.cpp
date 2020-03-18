void modifyUtil(Node* root, int* sum){
    if(root==NULL) return;
    modifyUtil(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum; 
    modifyUtil(root->left, sum);
}

void modify(Node **root)
{
    int sum = 0;
    modifyUtil(*root, &sum);
}
