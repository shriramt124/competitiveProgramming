 #include<iostream>
 using namespace std;
 #include<queue>
 
 class Node{
   public:
   int data;
   Node*left;
   Node*right;
   Node(int d){
       this->data = d;
       this->left = NULL;
       this->right = NULL;
       
   }
 };
 
 void insert(Node*& root,int data){
     if(root == NULL){
         root = new Node(data);
         
         return;
     }
     if(root->left == NULL and root->right == NULL){
         if(data<root->data){
             root->left = new Node(data);
         }else{
             root->right = new Node(data);
         }
         return;
     }
     if(data <root->data){
         insert(root->left,data);
     }else {
        insert(root->right,data); 
     }
 }
 void levelOrder(Node* root){
     //Using queue to implement Level order traversal of binary tree.
     queue<Node*>q;
     q.push(root);
     while(!q.empty()){
        int size = q.size();
        while(size--){
            Node*front = q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }cout<<endl;
     }
     
 }
 
 void insertBST(Node*&root){
     int data;
     cin>>data;
     while(data !=-1){
         insert(root,data);
         cin>>data;
     }
 }
 
 int main(){
     Node*root = NULL;
     insertBST(root);
     levelOrder(root);
     
     return 0;
 }