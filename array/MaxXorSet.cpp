int maxSubarrayXOR(int A[], int n)
{
    int index = 0;
    for(int i = INT_BITS-1 ; i>=0 ; i--){
        int maxEl = INT_MIN;
        int maxId = index;
        
        for(int j=index;j<n;j++){
            if( (A[j] & (1<<i)) && A[j]>maxEl ){
                maxEl = A[j];
                maxId = j;
            }
            
        }
        
        if(maxEl==INT_MIN) continue;
        
        swap(A[index], A[maxId]);
        maxId = index;
        
        for(int j=0;j<n;j++){
            if(j!=maxId && (A[j] & (1<<i))!=0){
                A[j] = A[j] ^ A[maxId];
            } 
        }
       
        index++;
    }
    int res=0;
    
    for(int i=0;i<n;i++) res = res ^ A[i];
    
    return res;
}