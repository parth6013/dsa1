#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int front,rear,cs,ms;

    Queue(int ds=5){
        arr = new int[ds];
        front=0;
        ms=ds;
        cs=0;
        rear=ms-1;
    }

    bool empty(){
        return cs==0;
    }

    bool full(){
        return cs==ms;
    }

    void push(int a){
        if(!full()){
            rear=(rear + 1)%ms;
            arr[rear]=a;
            cs++;
        }
        else{
            cout<<"queue is full cant push : "<<a<<endl;
        }
    }

    void pop(){
        if(!empty()){
            front=(front+1)%ms;
            cs--;
        }
    }

    void print(){
        
        while(!empty()){
            cout<<arr[front];
            pop();
        }
    }
};

int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.print();

}