// Striver DSA sheet
// Implement Queue using Linked List

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node(int data)
        {
            val = data;
            next = nullptr;
        }
};

class Queue 
{
    public: 
        bool isEmpty();
        void insert(int value);
        int peek();
        void remove();
        int size;
};

Node* front = nullptr;
Node* rear = nullptr;


bool Queue :: isEmpty()
{
    if(front == nullptr) return true;
    else return false;
}

void Queue :: insert(int value)
{
    Node* temp = new Node (value); 
    rear->next = temp;
    rear = temp;
    size++;
}
