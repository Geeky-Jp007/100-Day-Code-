struct Nodedetails{
    Node* ptr;
    int min,max;
};
Node* constructBst(int arr[], int n)
{
    if(n==0) return NULL;
    
    //index to iterate array
    int i=0;
    
    queue<Nodedetails> q;
    
    Nodedetails newNode;
    newNode.ptr = new Node(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    
    q.push(newNode);
    
    Node* root = newNode.ptr;
    
    while(i!=n){
        Nodedetails temp;
        temp = q.front();
        q.pop();
        
        if(i<n && arr[i]<=temp.ptr->data && arr[i]>temp.min){
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.min;
            newNode.max = temp.ptr->data;
            q.push(newNode);
            temp.ptr->left = newNode.ptr;
        }
        if(i<n && arr[i]>temp.ptr->data && arr[i]<temp.max){
            newNode.ptr = new Node(arr[i++]);
            newNode.min = temp.ptr->data;
            newNode.max = temp.max;
            q.push(newNode);
            temp.ptr->right = newNode.ptr;
        }
    }
    return root;
}