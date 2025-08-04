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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* ans = new ListNode(0);
        ListNode* merge =ans;
        while(head1 || head2){
            ListNode* temp = new ListNode();
            if(head1 && head2){
                if(head1->val <= head2->val){
                    temp->val = head1->val;
                    head1=head1->next;
                }
                else {
                    temp->val = head2->val;
                    head2 = head2->next;
                }
            }
            else if(head1){
                ans->next = head1;
                break;
                //temp->val = head1->val;
                //head1=head1->next;
            }
            else {
                ans->next = head2;
                break;
                //temp->val = head2->val;
                //head2 = head2->next;
            }
            ans->next = temp;
            ans = ans->next;
        }
        return merge->next;
    }
};