// leetcode
// linked list cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==nullptr) return false;
        if(head->next == nullptr) return false;
        ListNode* a=head;
        ListNode* b=head;
        while(a!=nullptr && b!=nullptr && b->next!=nullptr){
            a=a->next;
            b=b->next->next;
            if (a==b) return true;
        } 
        return false; 
    }
};
