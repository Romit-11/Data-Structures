#include<iostream>
#include<string.h>
using namespace std;

class Stack{
    public:
    int size;
    char top;
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
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


char stackTop(Stack *ptr){ 
    if(ptr->top==-1){
        return -1;
    }
    else{
        return ptr->arr[ptr->top];
    }
}

int prec(char ch){
    if(ch == '*'|| ch=='/'){
        return 3;
    }
    else if(ch == '+'|| ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='+'|| ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}


char *infixToPostfix(char *infix){
    Stack *sp = new Stack();
    sp->size = 10;
    sp->top-1;
    sp->arr = new char[sp->size];
    char *postFix = new char[strlen(infix)+1*sizeof(char)];
    int i = 0;
    int j = 0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postFix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(prec(infix[i])>prec(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postFix[j] = pop(sp);
                j++;
            }
        }
        }
        while(!isEmpty(sp)){
            postFix[j] = pop(sp);
            j++;
        }
        postFix[j]='\0';
        return postFix;
    }
    



int main(){
    char infix[] = "a-b+t/6";
    cout<<infixToPostfix(infix);
    
    return 0;
}