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
    void inorder(TreeNode* root, int &cnt, int &ans)
    {
        if(ans!=-1) return;
        if (root==NULL) return;
        inorder(root->left,cnt,ans);
        cnt--;
        if(cnt==0){
            ans = root->val;
            return;
        }
        inorder(root->right,cnt,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans =-1;
        inorder(root,k,ans); 
        return(ans);
    }
};