#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    char *arr;
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

void push(Stack *ptr, char value)
{
    ptr->top++;
    ptr->arr[ptr->top] = value;
    
}

char pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow";
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


int parenthesisMatch(char *exp){
    Stack *sp = new Stack();
    sp->size=sizeof(exp);
    sp->top = -1;
    sp->arr = new char[sp->size * sizeof(char)];

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(sp, exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                pop(sp);
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}



int main()
{
    char exp[] = "1*4+(14-5)";
    if(parenthesisMatch(exp)){
        cout<<"Expression is balanced";
    }
    else{
        cout<<"Expression is not balanced";
    }



    return 0;
}