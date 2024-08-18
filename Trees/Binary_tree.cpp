#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>

class Node{
   public:
   int value;
   Node*left;
   Node*right;
   Node(int data){
    value = data;
    left = NULL;
    right = NULL;
   }
};


void preOrderTraversal(Node*root){
    if(root == NULL){
        return;
    }
    cout<<root->value<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node*root){
    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout<<root->value<<" ";
    inOrderTraversal(root->right);
}

void PostOrderTraversal(Node*root){
    if(root == NULL) return;

     PostOrderTraversal(root->left);
     PostOrderTraversal(root->right);
     cout<<root->value<<" ";
}

void levelOrderTraversal(Node*root){
    if(root == NULL) return;
    queue<Node*>que;
    que.push(root);//first push root Node 
    //create a loop while queue is not empty 
    while(!que.empty()){
        int nodesAtcurrentLevel = que.size();//size at current level 
         
        while(nodesAtcurrentLevel-- ){
           Node*currNode = que.front();
           que.pop();//removing the front node 
           //check if right and left child presebt 
           if(currNode->left!=NULL){
            que.push(currNode->left);
           }
           if(currNode->right!=NULL){
            que.push(currNode->right);
           }
           cout<<currNode->value<<" ";
        }
        cout<<endl;

    }

}
void maximumDepth(Node*root,int &ans,int count){
   if(root == NULL){
     ans = max(ans,count);
     return;
   }
   maximumDepth(root->left,ans,count+1);
   maximumDepth(root->right,ans,count+1);
   
}

//count total leaf nodes in tree
int leafNode(Node*root){
    if(root == NULL) return 0;
    if(root->left == NULL and root->right == NULL) return 1;

   return( leafNode(root->right)+ leafNode(root->left));


}
int main(int argc, char const *argv[])
{
    Node*root = new Node(2);
    root->left = new Node(4);
    root->right  = new Node(10);
    root->left->left = new Node(6);
    root->left->left->left = new Node(8);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    cout<<"preorder traversal "<<endl;
    preOrderTraversal(root); cout<<endl;
    cout<<"Inorder traversal "<<endl;
    inOrderTraversal(root);cout<<endl;
    cout<<"Post order traveral"<<endl;
    PostOrderTraversal(root);cout<<endl;
    cout<<"level orde traversal "<<endl;
    levelOrderTraversal(root);cout<<endl;
     int ans = 0;
     maximumDepth(root,ans,0);
     cout<<"maximum depth is : "<<ans<<endl;;

     cout<<"total leafNodes is : "<<leafNode(root)<<endl;

    return 0;
}

//         2
//     4      10
//  6     5       11
