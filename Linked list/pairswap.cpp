struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    Node* temp = head, *temp1 = temp->next, *prev = temp;
    Node* newHead = temp->next;
    while(temp1){
        temp->next = temp1->next;
        temp1->next = temp;
        if(temp1 != newHead) prev->next = temp1;
        prev = temp;
        temp = temp?temp->next:NULL;
        temp1 = temp?temp->next:NULL;
        
    }
    return newHead;
}