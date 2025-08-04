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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = head;
        while(dummy && dummy->next){
            if(dummy->next->val == dummy->val){
                //ListNode* temp = dummy->next->next;
                //delete dummy->next;
                dummy->next = dummy->next->next;
                //delete temp;
            }
            else dummy = dummy->next;
        }
        // if(dummy->next && dummy->val == dummy->next->val){
        //     dummy->next = nullptr;
        // }
        return head;
    }
};