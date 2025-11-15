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
    ListNode* partition(ListNode* head, int x) {
        bool found = false;
        int index =0;
        ListNode* dummy = head;
        ListNode *start, *prev=nullptr;
        while(dummy){
            if(dummy->val>=x){
                found = true;
                start = dummy;
                break;
            }
            else {
                prev = dummy;
                index++;
                dummy=dummy->next;
            }
        }

        if(!found) return head;
        ListNode* temp= nullptr;
        dummy = start->next;
        ListNode* prev_greater = start;
        while(dummy){
            if(dummy->val < x){
                temp = dummy->next;
                prev_greater->next = temp;
                if(prev) prev->next = dummy;
                else head = dummy;
                dummy->next = start;
                prev = dummy;
                dummy = temp;
            }
            else {
                prev_greater = dummy;
                dummy = dummy->next;
            }
        }
        return head;
    }
};