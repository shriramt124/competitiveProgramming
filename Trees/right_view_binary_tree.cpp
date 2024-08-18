 
#include<iostream>
#include<vector>
 #include<queue>
using namespace std;
#include<map>
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
   void rightView(Node*root){
    if(root == NULL) return;

     queue<Node*>q;
   
     q.push(root);
     while(!q.empty()){
        //take nodes at current level 
        int size = q.size();
        while(size){
            //take current Node 
            Node*currNode = q.front();
            q.pop();
             if(size == 1){//pahan pe pahle check kar lena phir size-- karna
                cout<<currNode->value<<endl;
            }
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
            size--;
        }
        
     }
}
  
void columnTraversal(Node*root,vector<int>&ans){
           if(root == NULL) return;

           //create a queue of pair
           queue<pair<Node*,int>>q;
           //map to store collumn and value 
         
           q.push(make_pair(root,0));
             map<int,int>m;
           while(!q.empty()){
              //take the size of queue
              int nodesAtcurrentLevel = q.size();
              while(nodesAtcurrentLevel--){
                  //take the first pair from queue.front 
                  pair< Node *,int>p = q.front();
                  Node*currNode = p.first;
                  int currColumn = p.second;
                  q.pop();


                  //check if the value is already present in the map or not 
                  if(m.find(currColumn) == m.end()){
                       m[currColumn] = currNode->value;
                  }
                  if(currNode->left){
                    q.push(make_pair(currNode->left,currColumn-1));
                  }
                  if(currNode->right){
                    q.push(make_pair(currNode->right,currColumn+1));
                  }
              }
           }

           for(auto it:m){
            ans.push_back(it.second);
           }
}

//vertical order traversal 
void verticalTraversal(Node*root,vector<vector<int>>&ans){
     

     if(root == NULL) return;
     queue<pair<Node*,int>>q;
     q.push(make_pair(root,0));
     map<int,vector<int>>m;
     while(!q.empty()){
        //take the size 
        int size = q.size();

         while (size--)
         {
             //take the first pair from queue.front
             pair<Node*,int>p = q.front();
             q.pop();
             Node*currNode = p.first;
             int currColumn = p.second;
             m[currColumn].push_back(currNode->value);
             if(currNode->left){
                q.push(make_pair(currNode->left,currColumn-1));
             }
             if(currNode->right){
                q.push(make_pair(currNode->right,currColumn+1));
             }

         }
         
     }
     for(auto it:m){
        vector<int>temp;
        for(auto ele:it.second){
            temp.push_back(ele);
        }
        ans.push_back(temp);
     }
      
}

int main(int argc, char const *argv[])
{
    Node*root = new Node(2);
    root->left = new Node(4);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right = new Node(10);
    root->right->right = new Node(11);
    rightView(root);
    // vector<int>ans;
    //  columnTraversal(root,ans);
    //  for(auto ele:ans){
    //     cout<<ele<<" ";
    //  }cout<<endl;
    vector<vector<int>>ans;
    verticalTraversal(root,ans);
  for(auto row:ans){
    for(auto ele:row){
        cout<<ele<<" ";
    }cout<<endl;
  }

    return 0;
}

//             2
//        4        10
//    6       5         11