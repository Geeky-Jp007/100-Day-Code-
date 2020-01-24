#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void segregateEvenOdd(node **head, node **tail){
    node *prev = NULL;
    node *curr = *head;
    node *newTail = *tail;
    while((curr->data)%2!=0 && curr!=*tail){
        newTail->next = curr;

        newTail = newTail->next;
        curr = curr->next;
        newTail->next = NULL;

    }
    if((curr->data)%2==0 ){
        *head = curr;

        while(curr!=*tail){
            if((curr->data)%2==0){
                prev = curr;
                curr = curr->next;
            }
            else{
                prev->next = curr->next;
                curr->next=NULL;
                newTail->next=curr;
                newTail = newTail->next;
                curr = prev->next;
            }
        }
    }
    else prev = curr;

    if(newTail!=*tail && (((*tail)->data)%2)!=0){
        prev->next = (*tail)->next;
        (*tail)->next = NULL;
        newTail->next = *tail;
    }

}

void push(node** head, node** tail, int val){
    node* newNode = new node();
    newNode->data = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        *tail = *head;
    }
    else {
        (*tail)->next = newNode;
        (*tail) = (*tail)->next;
    }
}
void printList(node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }

}
int main(){
    int t;
    cin>>t;

    while(t-->0){
        int n,val;
        cin>>n;
        node* head = NULL;
        node* tail = NULL;

        for(int i=0;i<n;++i){
            cin>>val;
            push(&head, &tail, val);
        }
        segregateEvenOdd(&head, &tail);
        printList(head);

    }
}
