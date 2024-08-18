#include<iostream>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
    public:
    Node(int val){
        this->data = val;
        this->next = nullptr;
    }

   

};
 void insertBegin(int data,Node* &head){
        Node*newnode = new Node(data);
         newnode->next = head;
         head = newnode;
    }
    void insertEnd(int data,Node* &head){
        Node*temp = head;
        Node*newnode = new Node(data);
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void deleteHead(Node* &head){
        Node*temp = head;
        head = head->next;
        free(temp);
    }
    void deleteTail(Node* &head){
        if(head->next == nullptr || head == nullptr){
            free (head);
             return;
        }
        Node*prev = head;
        Node*curr = head;
        while(curr->next!=nullptr){
            prev = curr;
          curr = curr->next;
        }
        Node*toDelete = curr;
        prev->next = nullptr;
        free(toDelete);
    }
    void display(Node*head){
        Node*temp = head;
        while(temp){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }

int main(int argc, char const *argv[])
{
    Node*head = nullptr;
   insertBegin(1,head);
   insertBegin(2,head);
   insertBegin(5,head);
   insertBegin(9,head);
   insertEnd(34,head);
    display(head);
    deleteHead(head);
    display(head);
    deleteTail(head);
    display(head);

    return 0;
}
