#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *Next;

};

void LinkedTraversal(Node *ptr){
    while (ptr!=NULL)
    {
        cout<<"Element is: "<<ptr->data<<endl;
        ptr = ptr->Next;
    }
    
}


int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();


    head ->data = 7;
    head ->Next = second;

    second ->data = 1;
    second ->Next = third;

    third ->data = 18;
    third ->Next = fourth;

    fourth ->data = 3;
    fourth ->Next = NULL;

    LinkedTraversal(head);

    return 0;
}