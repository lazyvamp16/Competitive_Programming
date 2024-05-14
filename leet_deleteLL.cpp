// Remove Nth node from end of List

#include <iostream> 
using namespace std; 
  
// Node class to represent 
// a node of the linked list. 
class Node { 
public: 
    int data; 
    Node* next; 
  
    // Default constructor 
    Node() 
    { 
        data = 0; 
        next = NULL; 
    } 
  
    // Parameterised Constructor 
    Node(int data) 
    { 
        this->data = data; 
        this->next = NULL; 
    } 
}; 
  
// Linked list class to 
// implement a linked list. 
class Linkedlist { 
  
public: 
    Node* head;
    // Default constructor 
    Linkedlist() { head = NULL; } 
  
    // Function to insert a 
    // node at the end of the 
    // linked list. 
    void insertNode(int); 
  
    // Function to print the 
    // linked list. 
    void printList(); 
  
    // Function to delete the 
    // node at given position 
    void deleteNode(int); 
}; 
  
// Function to insert a new node. 
void Linkedlist::insertNode(int data) 
{ 
    // Create the new Node. 
    Node* newNode = new Node(data); 
  
    // Assign to head 
    if (head == NULL) { 
        head = newNode; 
        return; 
    } 
  
    // Traverse till end of list 
    Node* temp = head; 
    while (temp->next != NULL) { 
  
        // Update temp 
        temp = temp->next; 
    } 
  
    // Insert at the last. 
    temp->next = newNode; 
} 
  
// Function to print the 
// nodes of the linked list. 
void Linkedlist::printList() 
{ 
    Node* temp = head; 
  
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
 
    
    
    
Node* removeNthFromEnd(Node* head, int n) {
    int count=0;
    Node* mover = head;
    Node* mover2 = head;
    Node* temp;
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

int main()
{
    Linkedlist list;
    list.insertNode(1); 
    list.insertNode(2); 
    list.insertNode(3); 
    list.insertNode(4); 
    list.insertNode(5); 
    list.printList(); 
    cout << endl; 
    removeNthFromEnd(list.head,2);
    list.printList();

}