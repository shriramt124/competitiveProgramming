#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int data){
        left = NULL;
        right = NULL;
        val = data;
    }
};
class Bst{
    public:
    Node*root;
    Bst(){
     root = NULL;
    }
};
void insert(Node* &root,int data){
          Node*newnode = new Node(data);
          if(root == NULL){
            root = newnode;
            return;
          }
          Node*currnode = root;
          while(true){
          if(currnode->val > data){
            //it means we have to go to left
            if(currnode->left == NULL){
                currnode->left = newnode;
                return;
            }
            currnode = currnode->left;
          }else{
            if(currnode->right == NULL){
                currnode->right = newnode;
                return;
            }
            currnode = currnode->right;
          }
          }
}
void insertRecursively(Node*&root,int val){
    if(root == NULL){
        Node*newnode =new Node(val);
        root = newnode;
        return;
    }
     if(root->left == NULL and root->right == NULL){
        Node*newnode = new Node(val);
        if(root->val > val){
            //insert into left
            root->left = newnode;
            return;
        }else{
            root->right = newnode;
            return;
        }
        
     }

    if(root->val > val){
        //call left recursive call
     
        insertRecursively(root->left,val);
    }
    else if(root->val <=val){
         
        insertRecursively(root->right,val);
    }
}
Node*searchBST(Node*root,int val){
    if(root == NULL) return NULL;
    if(root->val == val){
        return root;
    }
    if(root->val > val){
        //call for left subtree
        return searchBST(root->left,val);
    }
    else{
        //call for right subTree
        return searchBST(root->right,val);
    }
}

Node*largetLeftInBst(Node*root){
        Node*curr = root;
        while(curr and curr->right){
            curr = curr->right;
            //largest value will lie on the right side of the tree so we have to traverse continualy to the right 
            //untill we reached to the right

        }
        return curr;
}
Node*deleteBST(Node*root,int key){
    if(root == NULL) return NULL;
    if(root->val < key){
        //it means we have to go to the right side 
        root->right = deleteBST(root->right,key);

    }
    else if(root->val > key){
         //we have to go to the left side 
         root->left = deleteBST(root->left,key);
    }
    //if root is the node to be deleted
    else{
        //if it has 0 child nodes 
        if(root->left == NULL and root->right == NULL){
            return NULL;
        }
        //if it has 1 child nodes
        else if(root->left == NULL){
            Node*temp = root->right;
            free (root);
            return temp;
        }
        else if(root->right == NULL){
            Node*temp = root->left;
            free(root);
            return temp;
        }
        //if it has two child nodes
        else{
            //find the justSmaller node on the left side 
            //swap the value of root from the justSmaller node
            //delete the just smaller node 
            Node*justSmallerNode = largetLeftInBst(root->left);
            root->val = justSmallerNode->val;
            root->left = deleteBST(root->left,justSmallerNode->val);
        }

    }
}

 Node*deleteLeafNodes(Node*root){
     if(root == NULL) return NULL;
     if(root->left == NULL and root->right == NULL){
        delete (root);
        return NULL;
     }
     root->left = deleteLeafNodes(root->left);
     root->right = deleteLeafNodes(root->right);
     return root;

 }

  void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
         if(root == NULL) return ;
         if(root->val == key){
             //pre-> rightmostValue in left subtree
             if(root->left){
                 Node*temp = root->left;
                 while(temp and temp->right){
                     temp = temp->right;
                 }
                 pre = temp;
             }
             //suc ->leftmost node in right subtree
             if(root->right){
                 Node*temp = root->right;
                 while(temp and temp->left){
                     temp = temp->left;
                 }
                 suc = temp;
             }
             return;
         }
         
         //case 2
         if(root->val > key){
             //root ke left 
             suc = root;
             findPreSuc(root->left,pre,suc,key);
         }else if(root->val < key){
             pre = root;
             findPreSuc(root->right,pre,suc,key);
         }
    }

void inorderTraverse(Node*root){
    if(root == NULL) return;
    inorderTraverse(root->left);
    cout<<root->val<<" ";
    inorderTraverse(root->right);
}



int main(int argc, char const *argv[])
{
    Bst bst1;
    insertRecursively(bst1.root,5);
    insertRecursively(bst1.root,3);
    insertRecursively(bst1.root,6);
    insertRecursively(bst1.root,11);
    insertRecursively(bst1.root,2);
    insertRecursively(bst1.root,4);
    insertRecursively(bst1.root,9);
   inorderTraverse(bst1.root);
   cout<<endl;
    // Node*node = searchBST(bst1.root,3);
    // inorderTraverse(node);
    // Node*res = deleteBST(bst1.root,3);
    // inorderTraverse(res);
    Node*del  =deleteLeafNodes(bst1.root);
    inorderTraverse(del);


  return 0;
    
}

//         5
//     3       6
//  2     4        11
//                9

