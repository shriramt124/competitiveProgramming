#include<iostream>
using namespace std;
 
#include<queue>
class stack{//stack using double queue
    public:
      queue<int>q1;
      queue<int>q2;
      
      void push(int x){
        //push in q2
        q2.push(x);
        //q1 to q2 push all element in q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        //again push all elements from q2 ro q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        //at the end q2 is always empty but q1 is not
      }
      int top(){
      if(q1.empty()){
        return -1;
      }
      return q1.front();
      }

      void pop(){
        if(q1.empty()){
            return;
        }
        cout<<"deleted element is : "<<q1.front()<<endl;;
        q1.pop();
      }

      bool isEmpty(){
        return q1.size() == 0;
      }
};


class Stack{//stack using single queue
    queue<int>q;
    public:
    void push(int x){
        q.push(x);
        for(int i = 0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int top(){
        if(q.empty()){
            return -1;
        }
    return q.front();
    }
    void pop(){
        if(q.empty()){
            return;
        }
        cout<<"deleted element is : "<<q.front()<<endl;
        q.pop();
    }
    

};
int main(int argc, char const *argv[])
{
    Stack st;
    st.push(45);
    st.push(56);
    st.push(78);
    st.pop();
    cout<<st.top()<<endl;

    return 0;
}
