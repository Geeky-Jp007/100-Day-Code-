Node* rotate(Node* head, int k) {
    // Your code here
    Node* tempH = head;
    Node* kHead = NULL;
    Node* k1Head = NULL;
    Node* tail = NULL;
    int n=0;
    while(tempH!=NULL ){
        if(tempH->next == NULL) tail = tempH;
        if(n==k-1) kHead = tempH;
        if(n==k) k1Head = tempH;
        tempH = tempH->next;
        n++;
    }
    if(n>=k+1){
        kHead->next = NULL;
        tail->next = head;
        head = k1Head;
    }

    return head;
}
