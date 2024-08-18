#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int top;
    int size;
   
    stack(int s){
        this->size = s;
        this->top = -1;
        arr = new int[size];

    }           
    void push(int item){
        if(top == size){
            cout<<"stack is full"<<endl;
            return;
        }   else{       
         top++;
         arr[top] = item;
        }

    }
    void pop(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
            return;
        }else{
        int item = arr[top];
        top--;
        cout<<"deleted item is :"<<item<<endl;
        }
    }
    bool isFull(){
        return top == size;
    }
    bool isEmpty(){
        return top == -1;
    }
    int peek(){
        if(top == -1){
            return -1;
        }
        return arr[top];
    }

};

int main(int argc, char const *argv[])
{
    stack st(5);
    st.push(5);
    st.push(4);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(87);
  
    cout<<"top of array is : "<< st.peek()<<endl;
   


    return 0;
}

