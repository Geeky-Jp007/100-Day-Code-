int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int count1 = 0, count2 = 0;
    Node* temp1 = head1, *temp2 = head2;
    while(temp1){
        count1++;
        temp1 = temp1->next;
    }
    while(temp2){
        count2++;
        temp2 = temp2->next;
    }
    
    temp1 = head1;
    temp2 = head2;
    int d = abs(count1-count2);
    
    while(temp1 && temp2){
        if(d){
            if(count1>count2){
                temp1 = temp1->next;
                d--;
                continue;
            }
            else{
                temp2 = temp2->next;
                d--;
                continue;
            }
        }
        else if(temp1==temp2) return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}