void deleteNode(Node *node)
{
   // Your code here
   Node* temp = NULL;
   while(node->next!=NULL){
       node->data = node->next->data;
       if(node->next->next == NULL) temp = node;
       node = node->next;
   }
   temp->next = NULL;
   free(node);


}
