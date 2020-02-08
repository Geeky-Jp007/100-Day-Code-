void sortList(Node** head)
{
    // Your Code Here
    Node* temp = *head;
    while(temp->next){
        Node* check = temp->next;
        if(check->data<0){
            temp->next = check->next;
            check->next = *head;
            *head = check;
        }
        if(!temp->next) break;
        if(temp->next->data>=0) temp = temp->next;
    }
}