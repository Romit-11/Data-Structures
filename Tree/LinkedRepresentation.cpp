#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data){
    Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){

    // Creating root Node using function.
    Node *p = CreateNode(13);

    // Creating second Node using function.
    Node *p1 = CreateNode(26);

    // Creating third Node using function.
    Node *p2 = CreateNode(39);

    //Linking nodes with rooot.
    p->left = p1;
    p->right = p2;
    

    /*

    // Creating Root node.
    Node *p = new Node();
    p->data = 13;
    p->left = NULL;
    p->right = NULL;

    // Creating second node.
    Node *p1 = new Node();
    p1->data = 26;
    p1->left = NULL;
    p1->right = NULL;

    // Creating third node.
    Node *p2 = new Node();
    p2->data = 39;
    p2->left = NULL;
    p2->right = NULL;

    // Linking second and third nodes to the root node.
    p->left = p1;
    p->right = p2;

    */
    
    return 0;
}