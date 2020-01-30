void removeTheLoop(Node *head)
{
     //Your code here
     Node* slow = head;
     Node* fast = head;

     int count = 0;
     while(fast!=NULL && fast->next!= NULL){
         fast = fast->next->next;
         slow = slow->next;
         if(fast==slow){
             count = 1;
             break;
         }
     }
     if(count){
        Node* begin = head;
        while(begin->next != fast->next){

            fast = fast->next;
            begin = begin->next;
        }
        fast->next=NULL;
     }
}
