#include<iostream>
using namespace std;

class Stack{
    public:
    int size;
    int top;
    int *arr;
};

int isEmpty(Stack *arr){
    if(arr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Stack *arr){
    if(arr->top==arr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    Stack *s = new Stack();
    s->size = 6;
    s->top=-1;
    s->arr = new int [s->size*sizeof(int)];
    
    s->arr[0]=5;
    s->top = 0;

    s->arr[0]=1;
    s->top = 1;

    s->arr[0]=4;
    s->top = 2;

    s->arr[0]=2;
    s->top = 3;

    s->arr[0]=8;
    s->top = 4;

    s->arr[0]=7;
    s->top = 5;


    if(isEmpty(s)){
        cout<<"The stack is empty";
    }
    else{
        cout<<"The stack is not emtpy";
    }

    cout<<"\n";

    if(isFull(s)){
        cout<<"The stack is full";
    }

    else{
        cout<<"The stack is not full";
    }

    return 0;
}