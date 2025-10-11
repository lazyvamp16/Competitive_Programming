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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = list1;
        ListNode* head =list1;
        for(int i=0; i<a-1; i++){
            first = first->next;
        }
        ListNode* second = first->next;
        for(int i=a; i<=b; i++){
            second = second->next;
        }
        //cout << first -> val << " " << second-> val;
        first->next = list2;
        while(first->next){
            first = first->next;
        }
        first->next = second;
        return head;
    }
};