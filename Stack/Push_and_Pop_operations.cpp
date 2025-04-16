#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *arr;
};

int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow";
        cout << "\n";
        cout << "Cannot push " << value;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow";
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(Stack *ptr, int i){
    if(ptr->top-i+1==0){
        cout<<"not a valid position";
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int stackBottom(Stack *ptr){
    if(ptr->top==-1){
        cout<<"Stack is Empty";
        return -1;
    }

    else{
        return ptr->arr[0];
    }
}

int stackTop(Stack *ptr){
    if(ptr->top==-1){
        cout<<"Stack is empty";
        return -1;
    }
    
    else{
        return ptr->arr[ptr->top];
    }
}

int main()
{

    Stack *s = new Stack();
    s->size = 8;
    s->top = -1;
    s->arr = new int[s->size * sizeof(int)];

    s->arr[0] = 5;
    s->top = 0;

    s->arr[1] = 1;
    s->top = 1;

    s->arr[2] = 4;
    s->top = 2;

    s->arr[3] = 2;
    s->top = 3;

    s->arr[4] = 8;
    s->top = 4;

    s->arr[5] = 5;
    s->top = 5;

    s->arr[6] = 9;
    s->top = 6;

    // s->arr[0]=13;
    // s->top = 7;

    // cout<<isFull(s);
    // cout<<"\n";
    // cout<<isEmpty(s);
    // cout<<"\n";

    // push(s, 15);
    // push(s, 14);
    cout<<"\n";
    // cout<<peek(s, 5);
    // cout<<"\n";
    // cout<<pop(s);

    cout<<stackBottom(s);
    cout<<"\n";
    cout<<stackTop(s);

    return 0;
}