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
    // DFS
    void dfs(TreeNode* root, int level, vector<vector<int>> &ans){
        if(!root) return;
        if(ans.size()==level) ans.push_back({root->val});
        else ans[level].push_back(root->val);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
    vector<vector<int>> levelOrderDFS(TreeNode* root){
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }

    // BFS
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};