#include<iostream>
using namespace std;
#include<vector>
class Node{
public:
int data;
vector<Node*>children;
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
void justGreater(Node*root,int x,Node*&ans){
          if(root == NULL) return ;
          if(root->data > x &&(ans == NULL|| root->data < ans->data)){
            //update the ans node
            ans = root;
          }
          for(Node*child:root->children){
            justGreater(child,x,ans);
          }

}
int main(int argc, char const *argv[])
{
    Node*root = new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));
    PreOrder(root);
    int x = 10;
    Node*ans = NULL;
    cout<<endl;
    justGreater(root,x,ans);
    cout<<ans->data<<" ";

    return 0;
}
