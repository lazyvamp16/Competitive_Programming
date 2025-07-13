class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // unordered_map<int,vector<int>> adj;
        // int n= isConnected[0].size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j) continue;
        //         if(isConnected[i][j]==1)
        //         adj[i].push_back(j);
        //     }
        // }
        int ans=0;
        vector<int> vis(isConnected[0].size(),0);
        for(int i=0; i<isConnected[0].size();i++){
            if(!vis[i])
            {
                ans++;
                bfs(i,isConnected,vis);
                //dfs2(i,isConnected,vis);
                //dfs(i,adj,vis);
            }
        }
        return ans;
    }
private:
    void dfs2(int node, vector<vector<int>>& adj, vector<int>&vis){
        vis[node]=1;
        for(int i=0;i<adj[0].size();i++){
            if(adj[node][i]==1 && !vis[i]) {
                dfs2(i,adj,vis);
            }
        }
    }

    void dfs(int node, unordered_map<int,vector<int>>adj, vector<int>&vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]) {
                dfs(i,adj,vis);
            }
        }
    }

    void bfs(int start, vector<vector<int>>& isConnected, vector<int>& vis)
    {
        vis[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=1;
            for(int i=0; i<isConnected[node].size(); i++){
                if(isConnected[node][i]==1 && vis[i]==0) {
                    //vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
};