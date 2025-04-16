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

Node *inOrderPredecessor(Node *root){
    root = root->left;
    while(root->right!= NULL){
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node * root, int val){
    Node *iPre; 
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }

    if(val<root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val>root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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

    inOrder(p);
    cout<<"\n";
    deleteNode(p,20);
    // cout<<p->data;
    cout<<"\n";
    inOrder(p);

    return 0;
}