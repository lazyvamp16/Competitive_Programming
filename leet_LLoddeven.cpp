// Odd Even Linked List


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head ==nullptr || head->next==nullptr)
            return head;
        ListNode* mover = head;
        ListNode* temp;
        ListNode* temp2;
        ListNode* dummy = head;
        ListNode* sec = head->next;
        int c=0;
        while(mover->next != nullptr)
        {
            temp2 = mover;
            temp = mover->next;
            mover->next= mover->next->next;
            mover = temp;
            c++;
        }
        if(c%2==0) mover->next = sec;
        else temp2->next = sec;
        return dummy;
    }
};
