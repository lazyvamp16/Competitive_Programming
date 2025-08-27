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
    TreeNode* f(int start, int end, vector<int>& nums){
        if (start>=end) return nullptr;
        int mx = *max_element(nums.begin()+start, nums.begin()+end);
        for(int i=start; i<end; i++){
            if(nums[i]==mx) {
                TreeNode* node = new TreeNode(mx);
                node->left = f(start, i, nums);
                node->right = f(i+1,end,nums);
                return node;
            }
        } 
        return nullptr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n= nums.size();
        TreeNode* head = f(0,n, nums);
        return head;
    }
};