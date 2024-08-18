#include <bits/stdc++.h>

 

class Node {
public:
        int data;
        Node* next;
        Node* child;

        Node(int data) {
                this->data = data;
                this->next = NULL;
                this->child = NULL;
        }
};

 
Node *merge(Node *down, Node *right) {
  if (down == NULL)
    return right;
  if (right == NULL)
    return down;

  Node *ansnode = new Node(-1);
  Node *ptr = ansnode;
  while (down!=NULL and right!=NULL) {
    if (down->data <= right->data) {
      ptr->child = down;
      ptr = ptr->child;
      down = down->child;
    } else {
      ptr->child = right;
      ptr = ptr->child;
      right = right->child;
    }
  }

  while (down!=NULL) {
    ptr->child = down;
    ptr = down;
    down = down->child;
  }
  while (right!=NULL) {
    ptr->child = right;
    ptr = right;
    right = right->child;
  }
  return ansnode->child;
}
Node* solv(Node* &head) {
  if (head == NULL || head->next == NULL)
    return head;

  Node *down = head;
  
  Node *right = solv(head->next);
  Node *ans = merge(down, right);
  return ans;
}
Node *flattenLinkedList(Node *head) {

  Node *ans = solv(head);
  return ans;
}
