class Solution {
public:
    bool dfs(int node, int col,vector<int> &vis, vector<vector<int>>& adj){
        vis[node]=col;
        //if(c[node]!=0 && c[node]!=col) return false;
        for(int i : adj[node]){
            if(vis[i]==0){
                if(dfs(i,-col,vis,adj)==false) return false;
            }
            else{
                if(vis[i]!= -col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i,1,vis,adj)==false) return false;
            }
        }
        return true;
    }
};