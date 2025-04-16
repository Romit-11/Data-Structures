#include<iostream>
using namespace std;

class Cir_Queue{
    public:
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(Cir_Queue*q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Cir_Queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}


void enqueue(Cir_Queue *q, int val){
    if(isFull(q)){
        cout<<"Queue Overflow"<<"\n";
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        cout<<"Enqueueing vlaue: "<<val<<"\n";
    }
}

int dequeue(Cir_Queue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<"Queue underflow";
    }
    else{
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}


int main(){
    Cir_Queue *q = new Cir_Queue();
    q->size = 8;
    q->f = 0;
    q->r = 0;
    // q->arr = new int(q->size*sizeof(int));
    q->arr = new int[q->size];

    
    enqueue(q,12);
    enqueue(q,24);
    enqueue(q,36);
    enqueue(q,48);
    enqueue(q,60);
    enqueue(q,72);
    enqueue(q,84);
    
    cout<<dequeue(q)<<"\n";
    cout<<dequeue(q)<<"\n";
    cout<<dequeue(q)<<"\n";
    cout<<dequeue(q)<<"\n";
    
    enqueue(q,96);
    enqueue(q,108);
    enqueue(q,120);
    enqueue(q,132);
    

    if(isEmpty(q)){
        cout<<"The Queue is empty"<<"\n";

    }
    if(isFull(q)){
        cout<<"The Queue is full";
    }

    return 0;
}