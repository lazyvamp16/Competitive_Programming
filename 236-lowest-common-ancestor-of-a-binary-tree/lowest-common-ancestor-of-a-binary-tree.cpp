/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        return root;
    }





    //Brute    
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> path1;
        stack<TreeNode*> path2;

        get_path(root, p, path1);
        get_path(root, q, path2);
        if(!root) return root;
        TreeNode* ans = root;
        while(!path1.empty() && !path2.empty()) {
            if((path1.top())->val==(path2.top())->val) {
            ans = path1.top();
            path1.pop();
            path2.pop();
            }
            else break;
        }
        return(ans);

    }
private:
    bool get_path(TreeNode* root, TreeNode* node, stack<TreeNode*> &path){

        if(!root) return false;
        if(root->val == node->val) {
            path.push(node);
            return true;
        }
        bool ans = (get_path(root->left,node,path) || get_path(root->right,node,path));
        if(ans){
            path.push(root);
        }
        return ans;
    }
};