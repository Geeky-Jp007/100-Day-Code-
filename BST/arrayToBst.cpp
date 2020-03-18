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
    bst* arrayToBst(int arr[], int low, int high){
        if(low>high) return NULL;
        int mid = (low+high)/2;
        bst* root = new bst(arr[mid]);
        root->left = arrayToBst(arr, low, mid-1);
        root->right = arrayToBst(arr, mid+1, high);
        return root;
    }
    void preorder(bst* root){
        if(root==NULL) return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};
int main(){
    bst b(0), *root=NULL;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        root = b.arrayToBst(arr, 0, n-1);
        b.preorder(root);
        cout<<endl;
    }
}