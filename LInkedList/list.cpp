#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node(int data){
        val = data;
        next =NULL;
    }
    void display(Node*head){
        Node*temp  = head;
        while(temp!=NULL){
            cout<<temp->val<<"--->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Node*head = new Node(4);
     
    return 0;
}
