#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int x){
        data = x;
    }
};


// Function to check if the Stack is full or not.
int isFull(Node *top){
    Node *ptr = new Node(1);
    if(ptr==NULL){
        cout<<"Stack is full";
        return 1;
    }
    else{
        return 0;
    }
}


//Function to check if the stack is empty or not.
int isEmpty(Node *top){
    if(top==NULL){
        cout<<"Stack is empty";
        return 1;
    }
    else{
        return 0;
    }
}


// Function to push data into stack.
Node *push(Node *top, int data){
    if(isFull(top)){
        cout<<"Stack overflow";
        return NULL;
    }
    else{
        Node *ptr = new Node(data);
        ptr->next = top;
        top = ptr;
        return top;
    }
    
}


//Function to pop top element and return it.
int pop(Node*top){
    if(isEmpty(top)){
        cout<<"Stack underflow";
        return -1;
    }
    else{
        Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(Node *top, int pos){
    Node *ptr = top;
    for(int i =0; (i<pos-1 && ptr!=NULL); i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

int stackTop(Node *top){
    if(isEmpty(top)){
        cout<<"Stack is empty";
        return -1;
    }
    else{
        return top->data;
    }
}

int stackBottom(Node *top){
    if(isEmpty(top)){
        cout<<"Stack is empty";
        return -1;
    }
    else{
        Node*ptr = top;
        while(ptr->next!=NULL){
            ptr= ptr->next;
        }
        return ptr->data;
    }
}


// Function to print Linked List.
void printData(Node*ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<"\n";
        ptr = ptr->next;
    }
}

int main(){

    Node *top = NULL;
    top = push(top, 12);
    top = push(top, 10);
    top = push(top, 5);
    top = push(top, 15);
    top = push(top, 1);

    cout<<"Element at the provided position is: "<<peek(top,2)<<"\n";
    cout<<"Top most element is: "<<stackTop(top)<<"\n";
    cout<<"Bottom element is: "<<stackBottom(top)<<"\n";

    // cout<<"Stack elements before poping top element."<<"\n";
    // printData(top);
    // cout<<"\n";
    // cout<<"Element which is poped.";
    // int x = pop(top);
    // cout<<x<<"\n \n";
    // cout<<"Elements after poping out elements";
    // printData(top);

    return 0;
}