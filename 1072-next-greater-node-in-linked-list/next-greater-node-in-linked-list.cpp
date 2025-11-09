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
    vector<int> nextLargerNodes(ListNode* head) {
        deque<int> ans;
        vector<int> ans2;
        stack<int> st;
        ListNode* dummy = head;
        ListNode* temp, *temp2;
        ListNode* prev = nullptr;
        while(head){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head = prev;

        while(head){
            int v = head->val;
            while(!st.empty()){
                if(v>=st.top()) st.pop();
                else break;
            }
            if(st.empty()) ans.push_front(0);
            else ans.push_front(st.top());
            st.push(v);
            head = head->next;
        }
        vector<int> v(ans.begin(),ans.end());
        return v;


    }
};