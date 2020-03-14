int maxLen(int arr[], int n) {
    // Your code here
    unordered_map<int,int> m;
    int presum=0,res=INT_MIN;
    for(int i=0;i<n;i++){
        if(!arr[i]) arr[i]=-1;
    }
    for(int i=0;i<n;i++){
        presum+=arr[i];
        if(arr[i]==0 && res==0) res=1;
        if(presum==0) res=i+1;
        if(m.find(presum)!=m.end()) res = max(res, i-m[presum]);
        else m[presum] = i;
    }
    return max(0,res);
}