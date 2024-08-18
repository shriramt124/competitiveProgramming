#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//creating the class Node 
//genetric tree is an N-ary tree which contains refrences of it's children nodes
// and it can have many children at one node

class Node{
 public:
 char data;
 vector<Node*>children;//we are pushing the Nodes in the array
 Node(int val){
    this->data = val;
 }
};

//preorder Traversal of generic tree (root left  right)
void PreOrder(Node*root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    for(Node*child:root->children){//when children array is empty then this for loop will get skipped and we will return
        PreOrder(child);
    }
    return;
}

//inordertraversal of  generic tree
void inorder(Node*root){
    if(root == NULL) return;

    //recursively print the child nodes except the last node 
    int n = root->children.size();
    for(int i = 0;i<n-1;i++){
        inorder(root->children[i]);
    }

    //print root node 
    cout<<root->data<<" ";
    //recursively print the last node
    if(n>0){
        inorder(root->children[n-1]);
    }
}

//print all the child nodes of a root recursively and then print the root node 
void postOrder(Node*root){
      if(root == NULL) return;
           //calling the childrens of root node recursively 
      for(Node*child:root->children){
        postOrder(child);
      }
      //at the end printing the root node value
      cout<<root->data<<" ";
}
void levelOrderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node*front = q.front();//deque root node
            q.pop();
             cout<<front->data<<" ";
             if(front->children.size()>0){
                for(Node*child:front->children){//enque all of its child nodes
                    q.push(child);
                }
             }

        }
        cout<<endl;
    }
     
}

int main(int argc, char const *argv[])
{
     //creating the rooot node 
     Node*root = new Node('A');
     root->children.push_back(new Node('B'));
     root->children.push_back(new Node('C'));
     root->children.push_back(new Node('D'));
     root->children[0]->children.push_back(new Node('E'));
     root->children[0]->children.push_back(new Node('F'));
     
     root->children[2]->children.push_back(new Node('G'));

     PreOrder(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
     postOrder(root);
     cout<<endl;
     levelOrderTraversal(root);
    return 0;
}
//      A
//  B    C      D
//E   F       G