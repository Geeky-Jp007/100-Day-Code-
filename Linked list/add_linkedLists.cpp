Node* addTwoLists(Node* first, Node* second) {
    // Code here
    Node* res = NULL;
    Node* head = NULL;
    int carry = 0, rem = 0, sum;
    while(first!=NULL || second!=NULL){

        if(first==NULL) {
            sum = second->data + carry;
            second = second->next;
        }
        else if (second==NULL){
            sum = first->data + carry;
            first = first->next;
        }
        else {
            sum = first->data + second->data + carry;
            second = second->next;
            first = first->next;
        }

        Node* temp = new Node(sum%10);
        if(res == NULL){
            res = temp;
            head = temp;
        }
        else{
            head->next = temp;
            head = head->next;
        }
        carry = sum/10;
    }
    if(carry){
        Node* temp = new Node(carry);
        head->next = temp;
        head = head->next;
    }
    return res;
}
