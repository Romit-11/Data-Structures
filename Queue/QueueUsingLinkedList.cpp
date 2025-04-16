#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

};

Node *f = NULL;
Node *r = NULL;


void showData(Node *head){
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"\n";
        ptr = ptr->next;
    }
}


int isFull(Node *n){
    // Node *n = new Node();
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Node *f){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


void enqueue(int val){
    Node *n = new Node();
    if(isFull(n)){
        cout<<"Queue overflow";
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}


int dequeue(){
    int val = -1;
    Node *ptr = f;
    if(isEmpty(ptr)){
        cout<<"Queue Underflow";
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}


int main(){
    
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    enqueue(55);

    cout<<"Elements in Queue after enqueueing: "<<"\n";
    showData(f);

    cout<<"\n";
    cout<<"Elements which are dequeueing: "<<"\n";
    cout<<dequeue()<<"\n";
    cout<<dequeue()<<"\n";
    cout<<dequeue()<<"\n";
    cout<<dequeue()<<"\n";

    cout<<"\n";
    cout<<"Elements remaining in queue after dequeueing: "<<"\n";
    showData(f);

    
    return 0;
}