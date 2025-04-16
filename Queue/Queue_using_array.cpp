#include<iostream>
using namespace std;

class Queue{
    public:
    int size;
    int f;
    int r;
    int *arr;

};

// Function to check if the Queue is Full.
int isFull(Queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the Queue is Empty.
int isEmpty(Queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}

// Funciton to print the data of Queue.
void printdata(Queue *q){
    if(isEmpty(q)){
        cout<<"Nothing to print"<<"\n";
    }

    else{
        for(int i = q->f+1; i<=q->r; i++){
            cout<<q->arr[i]<<" ";
        }
    }
}

// Function to enqueue the elements in the queue.
void enqueue(Queue *q, int val){
    if(isFull(q)){
        cout<<"Queue Oveflow"<<"\n";
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

// Function to dequeuing elements from queue.
int dequeue(Queue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<"Queue underflow"<<"\n";
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}


int main(){
    Queue *qu = new Queue();
    qu->size = 8;
    qu->f = -1;
    qu->r = -1;
    qu->arr = new int(qu->size*sizeof(int));
    
    
    
    enqueue(qu, 13);
    enqueue(qu, 26);
    enqueue(qu, 39);
    enqueue(qu, 52);
    enqueue(qu, 78);
    enqueue(qu, 91);
    // enqueue(qu, 104);
    // enqueue(qu, 104);
    cout<<dequeue(qu)<<"\n";
    cout<<dequeue(qu)<<"\n";
    cout<<dequeue(qu)<<"\n";
    cout<<dequeue(qu)<<"\n";
    enqueue(qu, 65);
    enqueue(qu, 117);
    enqueue(qu, 130);


    printdata(qu);



    // if(isEmpty(qu)){
    //     cout<<"The Queue is empty"<<"\n";

    // }
    // if(isFull(qu)){
    //     cout<<"The Queue is full";
    // }
    
    
    
    // cout<<" ";
    // cout<<dequeue(qu);
    // cout<<" ";
    // cout<<dequeue(qu);
    // cout<<" ";
    // cout<<dequeue(qu);
    // cout<<"\n";

    

    return 0;
}