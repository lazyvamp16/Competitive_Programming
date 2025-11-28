class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& val,
    vector<int>& vis,int &ans, int k){
        vis[node]=1;
        long sum=val[node];
        for(int i:adj[node]){
            if(!vis[i]) sum+=dfs(i,adj,val,vis,ans,k);
        }
        if(sum%k==0){
            ans+=1;
        }
        return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=0;
        vector<int> vis( n);
        dfs(0,adj,values,vis,ans,k);
        return ans;
        
    }
};