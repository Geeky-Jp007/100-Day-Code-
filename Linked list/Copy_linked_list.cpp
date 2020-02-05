Node *copyList(Node *head) {
    // Your code here
    Node* headC = head, *temp;
    while(headC){
        temp = headC->next;
        headC->next = new Node(headC->data);
        headC->next->next = temp;
        headC = temp;
    }
    
    headC = head;
   
    while(headC) {
        if(headC->next) headC->next->arb = headC->arb?headC->arb->next:headC->arb;
        headC = headC->next?headC->next->next:headC->next;
    }
    
    Node* org = head;
    Node* dup = head->next;
    temp = dup;
    
    while(org && dup){
        org->next = org->next?org->next->next:org->next;
        dup->next = dup->next?dup->next->next:dup->next;
        org = org->next;
        dup = dup->next;
    }
    
    return temp;
    
}