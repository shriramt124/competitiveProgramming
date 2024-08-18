#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        this->data = val;
        next = NULL;
    }
};
void insert(Node* &head,int value){
    Node*newnode = new Node(value);
    if(head == NULL){
        head = newnode;
        return;
    }
    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void findMiddle(Node*head){
    Node*slow = head;
    Node*fast = head->next;
    while(fast){
        slow = slow->next;
        fast =fast->next;
        if(fast == NULL){
            break;
        }
        fast = fast->next;
    }
    cout<<"middle of linked list is: "<<slow->data;
}

int main(int argc, char const *argv[])
{
    Node*head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    findMiddle(head);
    return 0;
}
