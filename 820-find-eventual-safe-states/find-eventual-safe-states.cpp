class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &ans){
        vis[node] = 1;
        pathVis[node] = 1;
        for(int adj : graph[node]){
            if(!vis[adj]){
                if (dfs(adj,graph,vis,pathVis,ans)) {
                    ans[node]=0;
                    return true;
                }
            }
            // else if(!pathVis[adj]){
            //     ans[node] =1 ;
            //     return false;
            // }
            else if(pathVis[adj]){
                ans[node]=0;
                return true;
            }
        }
        ans[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> ans(n,1);
        vector<int> safe;
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(i,graph,vis,pathVis,ans);
        }
        for(int i=0; i<n; i++){
            if(ans[i]) safe.push_back(i);
        }
        return safe;
    }
};