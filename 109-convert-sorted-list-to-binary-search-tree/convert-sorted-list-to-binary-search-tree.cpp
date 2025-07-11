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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* start, ListNode* end){
        if(start==end) return nullptr;
        ListNode* slow = start;
        ListNode* fast = start;

        while(fast!=end && fast->next!=end){
            fast = fast->next->next;
            slow = slow->next; 
        }
        // Slow is now at middle of list
        TreeNode* head = new TreeNode(slow->val);
        head->left = helper(start, slow);
        head->right = helper(slow->next, end);
        return head;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = NULL;
        // Cases with empty list
        if(!head) return root;

        // Cases with 1 element
        ListNode* slow=head->next;
        if(!slow) {
            root = new TreeNode(head->val);
            return root;
        }

        // Cases with 2 elements
        ListNode* fast=slow->next;
        if(!fast){
            TreeNode* next = new TreeNode(slow->val);
            if(head->val > slow->val) {
                root = new TreeNode(head->val,next,nullptr);
            }
            else root = new TreeNode(head->val,nullptr,next);
            return root;
        }

        // Cases with more than 2 elements
        return helper(head, nullptr);

        
        // This doesnt give a complete tree, 
        // Instead it will return a V shaped tree
        // Hence it is not what is expected
/*
        TreeNode* ans = root;
        TreeNode* dummy = root;
        TreeNode* node = new TreeNode(head->val);
        root->left = node;
        root = root->left;
        head = head->next;
        while(head!=slow){
            //cout << head->val;
            node = new TreeNode(head->val);
            root->right = node;
            root = root->right;
            head = head->next;
        }
        head = head->next;
        cout << head->val;
        while(head){
            //cout << head->val;
            node = new TreeNode(head->val);
            dummy-> right = node;
            head = head->next;
            dummy = dummy->right;
        }
        return ans;
*/

    }
};
/*
             3
            /  \
            0   4
           / \ / \
             1    5

*/