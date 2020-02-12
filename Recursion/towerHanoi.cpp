#include<bits/stdc++.h>
using namespace std;

void towerHanoi(int n, int a, int c, int b, int &count){
    if(n==1){
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<c<<endl;
        count++;
        return;
    }
    
    towerHanoi(n-1, a, b, c, count);
    cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<c<<endl;
    count++;
    towerHanoi(n-1, b, c, a, count);
    
}

int main()
 {
    //coding Life;
    int t;
    cin>>t;
    while(t-->0)
    {
        int count = 0;
        int n, a=1, b=2, c=3;
        cin>>n;
        towerHanoi(n, a, c, b, count);
        cout<<count<<endl;
    }
	return 0;
}