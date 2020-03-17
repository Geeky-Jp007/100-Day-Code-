#include<bits/stdc++.h>
using namespace std;

bool preorderCanBst(int preorder[], int n){
    stack<int> s;
    int root = INT_MIN;
    for(int i=0;i<n;i++){
        
        if(preorder[i]<root) return 0;
        
        while(!s.empty() && s.top()<preorder[i]){
            root = s.top();
            s.pop();
        }
        s.push(preorder[i]);
    }
    return 1;
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
        for(int i=0;i<n;i++) cin>>preorder[i];
        
        cout<<preorderCanBst(preorder, n)<<endl;
    }
	return 0;
}