#include<iostream>
using namespace std;
class Node{
    public:
    Node*next;
    Node*prev;
    int data;
    Node(int val){
    data = val;
    next = NULL;
    prev = NULL;
    }
};

void insert(Node* &head,Node* &tail,int value){
          Node*newnode = new Node(value);
          if(head == NULL and tail == NULL){
             head = newnode;
             tail =newnode;
             return;
          }
          tail->next = newnode;
          newnode->prev = tail;
          tail = newnode;

}
void deleteHead(Node* &head){
    Node*temp = head;
    head = head->next;
    head->prev = NULL;
    delete (temp);

}
void deleteTail(Node* &tail){
    Node*temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete (temp);
}
void printList(Node*head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<"<-->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

int main(int argc, char const *argv[])
{
    Node*head = NULL;
    Node*tail = NULL;
    insert(head,tail,1);
    insert(head,tail,2);
    insert(head,tail,6);
    insert(head,tail,9);
    printList(head);
    deleteHead(head);
    printList(head);
    deleteTail(tail);
    printList(head);
      
    return 0;
}
