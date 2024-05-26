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
    ListNode* middleNode(ListNode* head) {
        if(head ==nullptr) return head;
        if(head->next == nullptr) return head;
        ListNode* dummy = head;
        ListNode* mover = head;
        int count=0;
        while(mover!=nullptr)
        {
            mover = mover->next;
            count++;
        }
        int mid = ceil(count/2);
        for(int i=0; i<mid;i++) dummy = dummy->next;
        return dummy;
    }
};
