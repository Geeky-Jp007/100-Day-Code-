void swap(struct Node** first,struct Node** second){
    int temp = (*first)->data;
    (*first)->data = (*second)->data;
    (*second)->data = temp;
}

void correctBSTUtil(struct Node* root, struct Node** first, struct Node** middle, struct Node** last, struct Node** prev){
    if(root==NULL) return;
    
    correctBSTUtil(root->left, first, middle, last, prev);
    
    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = root;
            *middle = *prev;
        }
        else *last = root;
    }
    *prev = root;
    
    correctBSTUtil(root->right, first, middle, last, prev);
}
struct Node *correctBST( struct Node* root )
{
    Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    correctBSTUtil(root, &first, &middle, &last, &prev);
    //cout<<first->data<<middle->data;
    if(first && last) swap(&first, &last);
    else if(first && middle) swap(&first, &middle);
    return root;
}