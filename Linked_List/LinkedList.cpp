#include<iostream>
using namespace std;

// Making class
class Node{
    public:
    int data;
    Node *Next;

    Node(int value){
        data = value;
    }

};

// Making Function for traversal of Linked List.
void LinkedTraversal(Node *ptr){
    while (ptr!=NULL)
    {
        cout<<"Element is: "<<ptr->data<<endl;
        ptr = ptr->Next;
    }
    
}


int main(){

    //Assigning memory in heap and assigning values of elements of linkedList using constructor.
    Node *head = new Node(7);
    Node *second = new Node(1);
    Node *third = new Node(18);
    Node *fourth = new Node(3);

    //Making links between elements of Linked List.
    head ->Next = second;
    second ->Next = third;
    third ->Next = fourth;
    fourth ->Next = NULL;

    LinkedTraversal(head);

    return 0;
}