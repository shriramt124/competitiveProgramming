#include<iostream>
using namespace std;

class queue{
    public:
    int front;
    int rear;
    int *arr;
    int size;
    queue(int s){
        size = s;
      arr =  new int[size];
      front = 0;
      rear = 0 ;
    }
    void enqueue(int val){
        if(rear == size){
            cout<<"queue is full "<<endl;
            return;
        }
        arr[rear] = val;
        rear = rear+1;
    }
    int dequeue(){
          if(front == rear){
             
            return -1;
          }else{
          int value = arr[front];
          cout<<"deleted values is : "<<value<<endl;;
          front++;
          if(front == rear){
            front = 0;
            rear = 0;
          }
          return value;
          }
    }
    int peek(){
        if(front == rear){
            return -1;
        }
        return arr[front];

    }
    bool isEmpty(){
        if(front == rear){
            return true;
        }else
        return false;
    }
 
};
 
 int main(int argc, char const *argv[])
 {
    queue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(8); 
    q.enqueue(8);
    q.enqueue(89);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.peek()<<endl;

    return 0;
 }
 