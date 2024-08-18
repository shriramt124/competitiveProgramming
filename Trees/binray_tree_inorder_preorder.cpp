#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>

class TreeNode{
    public:
    int value;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data){
        value = data;
        left = NULL;
        right = NULL;
    }

};
TreeNode*solv(vector<int>preorder,int prestart,int preend,vector<int>inorder,int instart,int inend,unordered_map<int,int>&inmap){
    if(prestart>preend || instart > inend){
        return NULL;
    }
    TreeNode*rootNode = new TreeNode(preorder[prestart]); 
    int rootInorderIndex = inmap[rootNode->value];
    //left subree size 
    int leftsubTreesize = rootInorderIndex-instart;
    rootNode->left = solv(preorder,prestart+1,prestart+leftsubTreesize,inorder,instart,rootInorderIndex-1,inmap);

    rootNode->right  = solv(preorder,prestart+leftsubTreesize+1,preend,inorder,rootInorderIndex+1,inend,inmap);

    return rootNode;


}
TreeNode* buildtree(vector<int>&preorder, vector<int>&inorder) {
 unordered_map<int,int>inmap;
 for(int i = 0;i<inorder.size();i++){
    inmap[inorder[i]] = i;
 }
   return solv(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);

}
int main(int argc, char const *argv[])
{
    vector<int>inorder = {9,3,15,20,7};
    vector<int>preorder = {3,9,20,15,7};


    return 0;
}
