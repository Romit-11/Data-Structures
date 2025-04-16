// BST = Binary Search Tree.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data)
{
    Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(Node *root, int key){
    Node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            cout<<"Cannot insert because "<<key<<" already exists in BST";
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    Node *ptr = CreateNode(key);
    if(key<prev->data){
        prev->left = ptr;
    }
    else{
        prev->right = ptr;
    }
}

void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}



int main()
{

    Node *p = CreateNode(17);
    Node *p1 = CreateNode(10);
    Node *p2 = CreateNode(20);
    Node *p3 = CreateNode(5);
    Node *p4 = CreateNode(11);

    // Linking nodes with rooot.
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 9);
    cout<<"\n";
    // cout<<p->left->left->right->data;

    inOrder(p);


    return 0;
}