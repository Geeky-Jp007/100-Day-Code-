#include<bits/stdc++.h>
using namespace std;


int main()
 {
    //coding Life;
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;
        
        int arr[n];
        
        for(int i=0;i<n;i++) cin>>arr[i];
        
        for(int i=0;i<n;i+=k){
            int left = i;
            int right = min(i+k-1,n-1);
            while(left<right){
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    
	return 0;
}