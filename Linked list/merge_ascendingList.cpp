struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    Node* head = node1->data>=node2->data ? node2:node1;
    Node* tail = head;
    if(node1->data>=node2->data) node2 = node2->next;
    else node1 = node1->next;
    
    while(node1 || node2){
        Node* temp = NULL; 
        if(node1 && node2){
        if(node1->data>=node2->data){
            temp = node2;
            node2 = node2->next;
        }
        else{
            temp = node1;
            node1 = node1->next;
        }
        }
        else if(node1){
            temp = node1;
            node1 = node1->next;
        }
        else{
            temp = node2;
            node2 = node2->next;
        }
        temp->next = head;
        head = temp;
    }
    tail->next = NULL;
    return head;
}