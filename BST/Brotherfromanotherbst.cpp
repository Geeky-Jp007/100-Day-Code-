// given a sum find pair in two bst which is equal to x.

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    if(root1==NULL || root2==NULL) return 0;
    
    stack<Node*> s1;
    stack<Node*> s2;
    int count = 0;
    Node *top1, *top2;
    
    while(1){
        
        while(root1!=NULL){
            s1.push(root1);
            root1 = root1->left;
        }
        
        while(root2!=NULL){
            s2.push(root2);
            root2 = root2->right;
        }
        
        if(s1.empty() || s2.empty()) break;
        
        top1 = s1.top();
        top2 = s2.top();
        if((top1->data + top2->data) == x){
            count++;
            s1.pop();
            s2.pop();
            
            root1 = top1->right;
            root2 = top2->left;
        }
        else if((top1->data + top2->data) < x){
            s1.pop();
            root1 = top1->right;
        }
        else{
            s2.pop();
            root2 = top2->left;
        }
    }
    return count;
}