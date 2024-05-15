#include<bits/stdc++.h>
using namespace std;

class Node {
public:
     int data;
     Node* next;
     Node* prev;
     Node() : data(0), next(nullptr), prev(nullptr) {}
     Node(int x) : data(x), next(nullptr), prev(nullptr) {}
     Node(int x, Node* next, Node* prev) : data(x), next(next), prev(prev) {}
};



//CONSTRUCT LINKED LIST FROM ARRAY (STRIVER CN)
//passing as reference saves time as deep copy is not made
//changes in arr will be reflected in main
Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover=head;
    for (int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover=mover->next;
    }
    return head;
    
}

//PRINT LINKED LIST
void displayLL(Node* head)
{      
    Node* mover = head;
    while(mover != nullptr)
    {
        cout<<mover->data << " ";
        mover=mover->next;
    }
    cout << endl;
}


//INSERT NODE IN BEGINNIG ( STRIVER CN )
Node* insertAtFirst(Node* list, int newValue)
{
    Node* newhead = new Node(newValue);
    newhead->next = list;
    return newhead;

}

//DELETE LAST NODE (STRIVER CN)
Node *deleteLast(Node* &list){
    Node* mover = list;
    while(mover->next->next!=NULL)
    {
        mover =  mover->next;
    }
    mover->next=NULL;
    return(list);
}


//REVERSE LL (STRIVER CN LC)
Node* reverseList(Node* head) {
    Node* dummy = head;
    Node* nextNode = NULL;
    Node* prev = NULL;       
    while(dummy!=NULL)
    {
        nextNode = dummy->next;
        dummy->next = prev;
        prev = dummy;
        dummy = nextNode;
    }
    return prev;
}

void moveOnce(Node* head)
{
    head->data = 100;
}


//Doubly linked list (striver CN)
//remember to check for edge cases (empty LL)
Node * insertAtTail(Node *head, int k) {
    if(head==NULL) 
    {   
        head = new Node(k);
        return head;
    }

    Node* dummy = head;
    while(dummy->next!=nullptr)
    {   
        dummy = dummy->next;
    }
    Node* node = new Node(k);
    dummy->next = node;
    node->prev = dummy;
    return(head);
}

int main()
{
    vector<int> arr={1,2,3,4};
    Node* head = constructLL(arr);
    displayLL(head);
    //Node* newHead = insertAtFirst(head,0); //passed by value
    //deleteLast(head); //passed by reference
    //displayLL(newHead);
    //reverseList(head);
    //Node* newHead = reverseList(head);
    //moveOnce(head); //changes are made here as well
    //insertAtTail(head, 20);
    //displayLL(newHead);
    //displayLL(head);


}