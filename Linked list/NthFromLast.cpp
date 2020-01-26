
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* first = head;
       Node* second = head;
       int count = 0;
       while(first->next!=NULL){
           if(count<n-1){
               first = first->next;
               count++;
           }
           else{
               first = first->next;
               second = second->next;
           }
       }

       if(count<n-1) return -1;
       else return second->data;

}
