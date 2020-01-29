struct node* reverse(struct node* head, int k)
{
    node* prev = head;
    node* nxt = head->next;
    
    int count = 1;
    while(count<k && nxt!=NULL){
        node* temp = nxt->next;
        nxt->next = prev;
        prev = nxt;
        nxt = temp;
        count++;
    }
    if(nxt==NULL) head->next = NULL;
    
    else head->next = reverse(nxt, k);

    return prev;
}