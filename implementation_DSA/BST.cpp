#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node* left;
        Node* right;
        int data;

        Node(int d)
        {
            data=d;
            left=NULL;
            right=NULL;
        }      
};

//root needs to be passed as refernece so at each call the root is updated
//recursive method
Node* insertNode(Node* &root, int d )
{
    if (root==NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d>root->data)
    {
        root->right = insertNode(root->right,d);
    }
    else
    {
        root->left = insertNode(root->left,d);
    }
    return root;
}


//iterative method
Node* insertIterative(Node* root, int val)
{
    if(root==NULL) 
    {
        root = new Node(val);
        return(root);
    }
    Node* temp = root;
    while(temp!=NULL)
    {
        if(val>temp->data && (temp->right)) temp=temp->right;
        else if (val<temp->data && (temp->left)) temp=temp->left;
        else break; //don't forget this
    }
    if(val>temp->data) temp->right = new Node(val);
    else temp->left = new Node(val);
    return(root);
}


//CHECK DELETION OF NODE


//Returns in sorted manner
void Inorder(Node* node)
{
    if (node == NULL) return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}

//Search (babbar CN)
bool searchInBST(Node *root, int x) 
{
    if (root==NULL) return (false);
    if (root->data == x) return (true);
    if(x > root->data)
    {
        return(searchInBST(root->right,x));
    }
    else 
    {
        return(searchInBST(root->left,x));
    }
    return(false);
}


int main()
{
    Node* root = NULL;
    // if root is not passed as reference then
    // root = insertNode(root,10); 
    // can be used
    insertNode(root,10);
    insertNode(root,6);
    insertNode(root,20);
    insertNode(root,13);
    insertNode(root,25);
    insertIterative(root,15);
    Inorder(root);
    cout << endl;
    //cout << searchInBST(root,20);
    //cout << searchInBST(root,9);

}
