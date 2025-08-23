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
private:
    int maxheight(TreeNode* node){
        if(!node) return 0;
        int left = maxheight(node->left);
        int right = maxheight(node->right);
        return(1 + max(left,right));
    }

    int check(TreeNode* node){
        if(!node) return 0;
        int left = check(node->left);
        if(left==-1) return -1;
        int right = check(node->right);
        if(right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return(1 + max(left,right));
    }

public:
    bool isBalanced(TreeNode* root) {
        // if(!root) return true;
        // int left = maxheight(root->left);
        // int right = maxheight(root->right);
        // if(abs(left-right)>1) return false;
        // return (isBalanced(root->left) && isBalanced(root->right));
        if(check(root)==-1) return false;
        return true;
    }
};