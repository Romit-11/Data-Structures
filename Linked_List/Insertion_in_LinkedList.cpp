#include<iostream>
using namespace std;

// FORMATION OF LINKED LIST CLASS
class LinkedList{
    public:
    int data;
    LinkedList *next;

// CONSTRUCTOR FOR ASSIGNING VALUES
    LinkedList(int val){
        data = val;

    }
};



//FUNCTON TO INSERT ELEMENT AT BEGINING OF LINKED LIST.
LinkedList *insertAtFirst(LinkedList *head, int data){
    LinkedList *ptr = new LinkedList(data);
    ptr->next = head;
    return ptr;
}

//FUNCTION TO INSERT ELEMENT AT GIVEN INDEX.
LinkedList *insertAtRandom(LinkedList *head, int data, int index){
    LinkedList *ptr = new LinkedList(data);
    LinkedList *p = head;
    int i = 0;
    while(i!=(index-1)){
        i++;
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    
    return head;
}


//FUNCTION TO INSERT ELEMENT AT END OF LINKED LIST.
LinkedList *insertAtEnd(LinkedList *head, int data){
    LinkedList *ptr = new LinkedList(data);
    LinkedList *p = head;\
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}


//FUNCTION TO INSERT ELEMENT AFTER A GIVEN NODE.
LinkedList *insertAfterNode(LinkedList *head, LinkedList *prevNode, int data){
    LinkedList *ptr = new LinkedList(data);
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;

}


//FUNCTION TO SHOW DATA OF LINKED LIST
void showData(LinkedList *ptr){
    while(ptr!=NULL){
        cout<<"The element is: "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}


int main(){
    //Assigning Values of Elements and making links.
    //LinkedList *Head = new LinkedList(15);
    // Head->next = new LinkedList(20);
    // Head->next->next = new LinkedList(30);
    // Head->next->next->next = new LinkedList(10);
    // Head->next->next->next->next = NULL;

    //Assigning memory in heap and values of Elements.
    LinkedList *Head = new LinkedList(15);
    LinkedList *Second = new LinkedList(5);
    LinkedList *Third = new LinkedList(20);
    LinkedList *Fourth = new LinkedList(10);

    //Making Links Between elements.
    Head->next = Second;
    Second->next = Third;
    Third->next = Fourth;
    Fourth ->next = NULL;



    // Head->data=3;
    // Head->next=Second;

    // Second->data=5;
    // Second->next=Third;

    // Third->data=6;
    // Third->next=Fourth;

    // Fourth->data=4;
    // Fourth->next=NULL;


    // ELEMENTS BEFORE INSERTING.

    // showData(Head);

    // cout<<endl<<endl;


    //ELEMENTS AFTER INSERTING.

    // Head = insertAtFirst(Head, 40);

    // insertAtRandom(Head, 13, 2);

    // insertAtEnd(Head, 25);


    // insertAfterNode(Head, Head->next->next, 78);


    showData(Head);

    
    return 0;
}