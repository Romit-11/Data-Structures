#include<iostream>
using namespace std;

// FORMATION OF LINKED LIST CLASS

class LinkedList{
    public:
    int data;
    LinkedList *next;

// CONSTRUCTOR FOR ASSIGNING VALUES.
    LinkedList(int value){
        data = value;
    }

};


// DELETE FIRST ELEMENT OF LINKED LIST.

LinkedList *deleteFirstElement(LinkedList *ptr){
    LinkedList *p = ptr;
    ptr = ptr->next;
    free(p);
    return ptr;
}


// DELETE ELEMENT AT ANY GIVEN INDEX.

LinkedList *delete_At_Index(LinkedList *head, int index){
    // LinkedList *ptr = head;
    // int i = 0;
    // while(i!=(index-1)){
    //     ptr = ptr->next;
    //     i++;
    // }

    // LinkedList *q=ptr->next;
    // ptr->next=q->next;
    // free(q);
    // return head;


    //SECOND METHOD
    LinkedList *p = head;
    LinkedList *q = head->next;
    for(int i = 0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
    
}


// DELETE LAST ELEMENT OF LINKED LIST.

LinkedList *deleteLastElement(LinkedList *head){
    LinkedList *ptr = head;
    while(ptr->next->next!=NULL){
        ptr = ptr->next;
    }

    LinkedList *p = ptr->next;
    ptr->next = NULL;
    free(p);
    return head;

}


// DELETE ELEMENT AFTER A GIVEN NODE OR KEY.

LinkedList *Delete_After_GivenNode(LinkedList *head, LinkedList *prevNode){
    LinkedList *ptr = head;
    while(ptr!=prevNode){
        ptr = ptr->next;
    }
LinkedList *p = ptr->next;
ptr->next = p->next;
free(p);
return head;

}

// FUNCTION TO SHOW DATA OF LINKED LIST

void showData(LinkedList *ptr){
    while(ptr!=NULL){
        cout<<"The element is: "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

int main(){

        // //Assigning values of Elements.
        // LinkedList *Head = new LinkedList(15);
        // LinkedList *Second = new LinkedList(5);
        // LinkedList *Third = new LinkedList(20);
        // LinkedList *Fourth = new LinkedList(10);
    
        // //Making Links Between elements.
        // Head->next = Second;
        // Second->next = Third;
        // Third->next = Fourth;
        // Fourth ->next = NULL;

        
    //Assigning Values of Elements and making links.
    LinkedList *head = new LinkedList(5);
    head->next = new LinkedList(10);
    head->next->next = new LinkedList(15);
    head->next->next->next = new LinkedList(20);
    cout<<"Elements before deleting: "<<endl<<endl;
    showData(head);

    cout<<endl<<"Elements after deleting: "<<endl<<endl;
    // head = deleteFirstElement(head);

    // delete_At_Index(head, 2);

    // deleteLastElement(head);

    Delete_After_GivenNode(head, head);


    showData(head);


    return 0;
}