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
    TreeNode* f(int start, int end, int mx, vector<int>& nums){
        if (start>=end) return nullptr;
        TreeNode* node = new TreeNode(mx);
        int mxe=nums[start];
        int mxf = nums[end-1];
        int index;
        for(int i=start; i<end; i++){
            if(nums[i]==mx) {
                index = i;
                break;
            }
            mxe = max(mxe,nums[i]);
        } 
        for(int i=index+1; i<end; i++){
            mxf = max(mxf,nums[i]);
        }
        node->left = f(start, index, mxe, nums);
        node->right = f(index+1,end,mxf, nums);
        return node;;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n= nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        TreeNode* head = f(0,n, mx, nums);
        return head;
    }
};