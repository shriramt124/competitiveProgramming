#include<iostream>
using namespace std;
#include<vector>
class Node{
  public:
  int data;
  Node*left;
  Node*right;
  Node(int val){
    data  = val;
    left = NULL;
    right = NULL;
  }  
};
int findIndex(vector<int>inorder,int instart,int inend,int key){
    for(int i = instart;i<=inend;i++){
     if(inorder[i] == key) return i;
    }
    return -1;
}
Node*solv(vector<int>preorder,int prestart,int preend,vector<int>inorder,int instart,int inend){
    if(prestart>preend  || instart > inend){
     return NULL;
    }
    Node*root = new Node(preorder[prestart]);
    int rootIndex = findIndex(inorder,instart,inend, root->data);
    int leftSubtreeSize = rootIndex-instart;
    root->left = solv(preorder,prestart+1,prestart+leftSubtreeSize,inorder,instart,rootIndex-1);
    root->right = solv(preorder,prestart+leftSubtreeSize+1,preend,inorder,rootIndex+1,inend);
    return root;
}
void traversal(Node*root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);

}
int main(int argc, char const *argv[])
{
    vector<int>preorder = {10,5,3,8,20,15,25};
    vector<int>inorder = {3,5,8,10,15,20,25};
    int prestart = 0;
    int instart = 0;
    int preend = preorder.size()-1;
    int inend = inorder.size()-1;
    Node*ans = solv(preorder,prestart,preend,inorder,instart,inend);
    traversal(ans);
    return 0;
}

