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
    bst* deleteval(bst* root,int value){
        if(root==NULL) return root;

        if(root->data > value){
            root->left = deleteval(root->left, value);
            return root;
        }
        else if (root->data < value){
            root->right = deleteval(root->right, value);
            return root;
        }
        //found root!!!
        if(root->left == NULL){
            bst* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            bst* temp = root->left;
            delete root;
            return temp;
        }

        //if root has two child we check for successor and right elements 
        //of successor is connected to left of parent of successor.

        else{
            bst *successor = root->right;
            bst *parent_successor = root->right;

            while(successor->left!=NULL){
                parent_successor = successor;
                successor = successor->left;
            }

            parent_successor->left = successor->right;
            root->data = successor->data;
            delete successor;
            return root;
        }

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
    int del;
    cin>>del;

    b.deleteval(root,del);

    b.inorder(root);

    cout<<endl;
    return 0;
}