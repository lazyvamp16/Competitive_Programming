// 2807. Insert Greatest Common Divisors in Linked List
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
    int gcd(int a,int b){
        for(int i=min(a,b);i>1;i--)
        {
            if (a%i==0 && b%i==0) return i;
        }
        return 1;
    }
    int gcd2(int a,int b)
    {
        if(b==0) return a;
        return gcd2(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* mover = head;
        ListNode* temp;
        while(mover->next!=nullptr){
            temp = mover->next;
            int g = gcd2(mover->val, temp->val);
            mover->next = new ListNode(g,temp);
            mover = temp;
        } 
        return head;
    }
};
