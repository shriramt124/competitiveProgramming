#include<iostream>
using namespace std;

class Node{
   public:
   int val;
   Node*next;
   Node(int data){
   this->val = data;
   next = NULL;
   }
};
// function to print the linked list
void display(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->val << "-->";
    temp = temp->next;
  }
  cout << "NULL";
}

void addAtTail(Node *&head, int data)
{
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new Node(data);
}

Node*merge(Node*l1,Node*l2){
  Node *ptr = new Node(-1);
  Node *curr = ptr;
   while(l1 != NULL && l2!= NULL){
    if(l1->val <= l2->val){
    curr->next= l1;
    l1 = l1->next;
    }else{
    curr->next= l2;
    l2 = l2->next;
    }
    curr = curr->next;
   }
   //if any one of them left
   if(l1!=NULL){
   curr->next= l1;
   l1 = l1->next;
   }
   if(l2 != NULL){
   curr->next= l2;
   l2 = l2->next;
   }
   return ptr->next;
  
}

Node*mergeSort(Node*head){
//we will folow the mergeSort
if(head == NULL or head->next == NULL) return head;
Node*slow = head;
Node*fast = head;
Node*temp = head;
while(fast != NULL and fast->next != NULL){
temp = slow;
slow = slow->next;
fast = fast->next->next;
 
}

//now slow pints to the mid
//fast points to the end
//temp points to the last element of the first half
//break the list on two halves
temp->next = NULL;
Node *l1 = mergeSort(head);
Node *l2 = mergeSort(slow);//slow points to the start of the second half

return merge(l1, l2);

}

int main(){
  Node *head = new Node(43);
  addAtTail(head, 23);
  addAtTail(head, 12);
  addAtTail(head, 56);
  addAtTail(head, 78);
  addAtTail(head, 90);
  display(head);
  cout << endl;

  Node *ans = mergeSort(head);
  display(ans);

  return -0;
}

