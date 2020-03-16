#include<bits/stdc++.h>
using namespace std;

class bst{
    int data;
    bst *left, *right;
    public:
    bst(int x){
        data = x;
        left = right = NULL;
    }
    bst* insert(bst* root,int value){
        if(root==NULL) return new bst(value);
        else if(root->data > value) root->left = insert(root->left,value);
        else root->right = insert(root->right,value);
        return root;
    }
    void inorder(bst* root){
        if(root==NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};
int main(){
    bst b(0), *root=NULL;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        if(!i) root = b.insert(root,data);
        else b.insert(root,data);
    }
    b.inorder(root);
    cout<<endl;
    return 0;
}