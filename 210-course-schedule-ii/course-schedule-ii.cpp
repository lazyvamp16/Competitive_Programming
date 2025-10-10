class Solution {

public:
    void topo(int node,vector<vector<int>>& adj, vector<int>&vis,
    vector<int>& ans) {
        vis[node]=1;
        for(int nei : adj[node]){
            if(!vis[nei]){
                topo(nei,adj,vis,ans);
                
            }
        }
        ans.push_back(node);
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        vector<int> vis(n);
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};