#include<bits/stdc++.h>
using namespace std;

void preToPostUtil(int preorder[], int n, int* preindex, int min, int max){
    if(*preindex==n) return;
    
    if(preorder[*preindex]<min || preorder[*preindex]>max) return;
    
    int val = preorder[*preindex];
    *preindex = *preindex +1;
    
    preToPostUtil(preorder, n, preindex, min, val);
    preToPostUtil(preorder, n, preindex, val, max);
    cout<<val<<" ";
}

void preToPost(int preorder[], int n){
    int preindex = 0;
    preToPostUtil(preorder, n, &preindex, INT_MIN, INT_MAX);
}

int main()
 {
    //coding Life;
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int preorder[n];
        for(int i=0;i<n;++i) cin>>preorder[i];
        
        preToPost(preorder, n);
        
        cout<<endl;
        
    }
	return 0;
}