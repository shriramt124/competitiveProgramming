#include<iostream>
using namespace std;
class cirqueue{
    public:
    int size;
    int rear;
    int front;
    int *arr;
    cirqueue(int s){
        size = s;
        rear = -1;
        front = -1;
        arr = new int[size];
    }
    void enqueue(int value){
        //two condidtions of queue to be full 
        if((front == 0 and rear == size-1) and (rear = (front-1))){
            cout<<"queue is full" <<endl;
            return;
        }
        //push
        if(front == -1){
            //you are inserting first element 
            front = rear = 0;
        }
       else if(front!=0 and rear == size-1){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = value;
    }
    void dequeue(){
        //check if empty
        if(front == -1){
         cout<<"queue is emptuy"<<endl;
         return;
        }
        if(front == rear){//it means single element is present
        cout<<"deleted element is : "<<arr[front]<<endl;
        front = rear = -1;
        return;

        }
        else if(front == size-1){
            //front reaches to the end then again move back front to start 
            cout<<"deleted element is : "<<arr[front]<<endl;
            front = 0;
            return;
        }
        else{
            cout<<"deleted element is : "<<arr[front]<<endl;
            front ++;
            return;
        }

    }
    int peek(){
        return arr[front];
    }

};
int main(int argc, char const *argv[])
{
    cirqueue q(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(78);
    q.dequeue();
    cout<<q.peek()<<endl;
    return 0;
}
