#include<iostream>
using namespace std;

class DEQueue{
    public:
    int size;
    int f;
    int r;
    int *arr;
};

//Function to check if the function is Full.
int isFull(DEQueue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to check if the function is Empty.
int isEmpty(DEQueue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to print elements of DEQueue.
void printdata(DEQueue *q){
    if(isEmpty(q)){
        cout<<"Nothing to print";
    }

    else{
        for(int i = q->f+1; i<=q->r; i++){
            cout<<q->arr[i]<<" ";
        }
    }
}

//Function to enqueue elements in rear of DEQueue.
void enqueueR(DEQueue *q, int val){
    if(isFull(q)){
        cout<<"Queue overflow"<<"\n";
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

//Function to enqueue elements in front of DEQueue.
void enqueueF(DEQueue *q, int val){
    if(q->f==-1){
        cout<<"No place in front for inserting"<<"\n";
    }
    else{
        q->arr[q->f]=val;
        q->f--;
    }
}

//Function to dequeue elements from front of DEQueue.
int dequeueF(DEQueue *q){
    int val = -1;
    if(isEmpty(q)){
        cout<<"Stack Underflow"<<"\n";
    }
    else{
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

//Function to dequeue elements from rear of DEQueue.
int dequeueR(DEQueue *q){
    int val = -1;
    if(isEmpty(q)){
        cout<<"Stack Underflow"<<"\n";
    }
    else{
        val = q->arr[q->r];
        q->r--;
    }
    return val;
}


int main(){
    DEQueue *q = new DEQueue();
    q->f = -1;
    q->r = -1;
    q->size = 4;
    q->arr = new int[sizeof(int)];

    // enqueueF(q, 5);

    enqueueR(q,10);
    enqueueR(q,15);
    enqueueR(q,20);
    enqueueR(q,25);

    cout<<dequeueF(q)<<"\n";
    cout<<dequeueF(q)<<"\n";

    enqueueF(q,5);
    enqueueF(q,10);
    // enqueueF(q,10);
    // cout<<dequeueR(q)<<"\n";

    printdata(q);

    return 0;
}