#include<iostream>
using namespace std;
#include<vector>
template <typename T>
class Stack{
    private:
    vector<T>arr;
    public:
    void push(T item){
        arr.push_back(item);
    }
    void pop(){
        if(!arr.size() == 0){
            arr.pop_back();
        }
    }
    T top(){
        if(arr.size() == 0){
            throw runtime_error("Stack is empty");
        }
        return arr.back();
    }

    bool empty(){
        return arr.size() == 0;
    }

    size_t size(){
        return arr.size();
    }

};

int main(int argc, char const *argv[])
{
    Stack<int>st;
    st.push(34);
    st.push(4);
   // cout<<st.top()<<endl;
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

    Stack<string>a;
    a.push("shriram");
    a.push("tiwari");
    a.push("arjun");
    a.push("palher");
    while(not a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }cout<<endl;
    return 0;
}
