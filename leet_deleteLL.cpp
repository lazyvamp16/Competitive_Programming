// Remove Nth ListNode from end of List

#include <iostream> 
using namespace std; 
  
// ListNode class to represent 
// a ListNode of the linked list. 
class ListNode { 
public: 
    int data; 
    ListNode* next; 
  
    // Default constructor 
    ListNode() 
    { 
        data = 0; 
        next = NULL; 
    } 
  
    // Parameterised Constructor 
    ListNode(int data) 
    { 
        this->data = data; 
        this->next = NULL; 
    } 
}; 
  
// Linked list class to 
// implement a linked list. 
class Linkedlist { 
  
public: 
    ListNode* head;
    // Default constructor 
    Linkedlist() { head = NULL; } 
  
    // Function to insert a 
    // ListNode at the end of the 
    // linked list. 
    void insertListNode(int); 
  
    // Function to print the 
    // linked list. 
    void printList(); 
  
    // Function to delete the 
    // ListNode at given position 
    void deleteListNode(int); 
}; 
  
// Function to insert a new ListNode. 
void Linkedlist::insertListNode(int data) 
{ 
    // Create the new ListNode. 
    ListNode* newListNode = new ListNode(data); 
  
    // Assign to head 
    if (head == NULL) { 
        head = newListNode; 
        return; 
    } 
  
    // Traverse till end of list 
    ListNode* temp = head; 
    while (temp->next != NULL) { 
  
        // Update temp 
        temp = temp->next; 
    } 
  
    // Insert at the last. 
    temp->next = newListNode; 
} 
  
// Function to print the 
// ListNodes of the linked list. 
void Linkedlist::printList() 
{ 
    ListNode* temp = head; 
  
    // Check for empty list. 
    if (head == NULL) { 
        cout << "List empty" << endl; 
        return; 
    } 
  
    // Traverse the list. 
    while (temp != NULL) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
} 
 
    
    
    
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count=0;
    ListNode* mover = head;
    ListNode* mover2 = head;
    ListNode* temp;
    while(mover->next != nullptr)
    {
        mover = mover->next;
        count++;
    }
    delete mover;
    for(int i=0;i<=(count-n);i++){
        temp = mover2;
        mover2 = mover2->next;
    }
    temp->next = mover2->next;
    delete mover2;
    delete temp;
    return(head);
}


ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode* mover1 = head;
    ListNode* mover2 = head;
    ListNode* temp;
    for(int i=0; i<n; i++)
    {
        mover1 = mover1->next;
    }
    if(mover1 == nullptr)
    {
        if(head->next ==nullptr) return(nullptr);
        return(head->next);
    }
    while(mover1->next!= nullptr)
    {
        mover1 = mover1->next;
        mover2 = mover2->next;  
    }
    temp = mover2->next;
    //cout << temp->data << " " << mover2->data << endl;
    mover2->next = temp->next;
    delete temp;
    return(head);
}

int main()
{
    Linkedlist list;
    list.insertListNode(1); 
    //int n=1;
    list.insertListNode(2); 
    list.insertListNode(3); 
    list.insertListNode(4); 
    list.insertListNode(5); 
    int n=2;
    list.printList(); 
    cout << endl; 
    removeNthFromEnd2(list.head,n);
    list.printList();

}