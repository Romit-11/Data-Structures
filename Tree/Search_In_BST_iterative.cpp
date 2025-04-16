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

int isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }

    else
    {
        return 1;
    }
}

Node *search(Node *root, int key)
{
    while(root!=NULL){
        if(root->data == key){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
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

    // Calling function to print preorder of tree.
    //  preOrder(p);
    //  cout<<"\n";
    //  postOrder(p);
    //  cout<<"\n";
    //  inOrder(p);
    cout << "\n";
    if (isBST(p))
    {
        cout << "Yes, Given tree is a binary search tree";
    }
    else
    {
        cout << "No, Given tree is not a binary search tree";
    }

    cout<<"\n";

    Node * n = search(p, 5);

    if(n!=NULL){
        cout<<"Element found: "<<n->data;
    }
    else{
        cout<<"Element not found";
    }

    return 0;
}