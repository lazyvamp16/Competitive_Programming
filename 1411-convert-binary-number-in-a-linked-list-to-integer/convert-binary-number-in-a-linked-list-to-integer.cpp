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
    int getDecimalValue(ListNode* head) {
        stack<int> st;
        while(head!=NULL){
            st.push(head->val);
            head = head->next;
        }
        int i=0,ans=0;
        while(!st.empty()){
            ans+=(st.top()*pow(2,i));
            st.pop();
            i++;
        }
        return ans;
    }
};