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

// Function for Pre-Order Traversal in binary tree.
void preOrder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for Post-order Traversal in binary tree.
void postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

// Function for In-Order Traversal in binary tree.
void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}


int main(){

    Node *p = CreateNode(4);
    Node *p1 = CreateNode(1);
    Node *p2 = CreateNode(6);
    Node *p3 = CreateNode(5);
    Node *p4 = CreateNode(2);

    //Linking nodes with rooot.
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //Calling function to print preorder of tree.
    preOrder(p);
    cout<<"\n";
    postOrder(p);
    cout<<"\n";
    inOrder(p);
    
    return 0;
}