#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>
#include<vector>
class Node{
public:
int data;
vector<Node*>children;
Node(int val){
    this->data = val;
}
};
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
void mirrorTree(Node*root){
    if(root == NULL) return;
       if(root->children.size() <2) return;
    reverse(root->children.begin(),root->children.end());
    for(Node*child:root->children){
        mirrorTree(child);
    }
}
void serializedTree(Node*root,string &ans){
    if(root == NULL) return;

    ans+= to_string(root->data) + ":"+to_string(root->children.size())+":";
    for(Node*child:root->children){
        ans+=to_string(child->data) + ",";

    }
    //last wale me bhi , lag jayega 
    if(root->children.size()!=0)
    ans.pop_back();//to remove the last ,
    ans+='\n';
    for(Node*child:root->children){
        serializedTree(child,ans);
    }

}

int main(int argc, char const *argv[])
{
    Node*root = new Node(10);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(100));
    root->children[1]->children.push_back(new Node(1));
    root->children[3]->children.push_back(new Node(7));
    root->children[3]->children.push_back(new Node(8));
    root->children[3]->children.push_back(new Node(9));
    levelOrderTraversal(root);
    mirrorTree(root);
    levelOrderTraversal(root);
    string ans = "";
    serializedTree(root,ans);
    cout<<ans<<endl;
    return 0;
}
